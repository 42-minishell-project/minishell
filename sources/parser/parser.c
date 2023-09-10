/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:05:38 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 16:16:45 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "parser/token.h"
#include "parser/cursor.h"
#include "env/env.h"
#include "command/command.h"
#include "utils/chr_array.h"
#include "utils/str_array.h"
#include "utils/io_array.h"
#include "utils/cmd_array.h"
#include "parser/cursor.h"
#include "command/open_io.h"

void	expand_env(t_cursor *s)
{
	char		c;
	t_chr_arr	*name;
	char		*env_value;

	forward_cursor(s);
	c = peek_cursor(s);
	if (c == '?')
	{
		forward_cursor(s);
		push_cursor(s, get_last_exit_code(), 0);
		return ;
	}
	name = new_chr_array();
	if (c == '_' || ft_isalpha(c))
		while (1)
		{
			c = peek_cursor(s);
			if (!c || !(c == '_' || ft_isalnum(c)))
				break ;
			push_chr_array(name, forward_cursor(s));
		}
	if (name->size == 0)
		push_cursor(s, "$", 0);
	else
	{
		env_value = find_env(name->arr);
		if (env_value)
			push_cursor(s, env_value, 0);
	}
	delete_chr_array(name);
}

char	peek_cursor_with_env(t_cursor *s)
{
	char	c;

	c = peek_cursor(s);
	if (c == '$')
	{
		expand_env(s);
		c = peek_cursor(s);
	}
	return (c);
}

int	is_special(t_cursor *s, char c)
{
	if (s->cur->flag & CURSOR_SPECIAL)
	{
		if (c == '<' || c == '>' || c == '|')
			return (1);
	}
	return (0);
}

t_special_type	check_special_type(t_cursor *s)
{
	char	c;

	if (s->cur->flag & CURSOR_SPECIAL)
	{
		c = peek_cursor(s);
		if (c == '>' || c == '<' || c == '|')
			forward_cursor(s);
		if (c == '>')
		{
			if (peek_cursor(s) == '>')
			{
				forward_cursor(s);
				return (SP_OUT_APPEND);
			}
			return (SP_OUT);
		}
		else if (c == '<')
		{
			if (peek_cursor(s) == '<')
			{
				forward_cursor(s);
				return (SP_IN_HEREDOC);
			}
			return (SP_IN);
		}
		else if (c == '|')
			return (SP_PIPE);
	}
	return (SP_NONE);
}

int	unexpected_eof_matching_error(char quote)
{
	ft_putstr_fd("unexpected EOF while looking for matching `", STDERR_FILENO);
	ft_putchar_fd(quote, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	return (-1);
}
int	syntax_error_unexpected_eof(void)
{
	printf("syntax error: unexpected end of file\n");
	return (-1);
}
int	syntax_error_unexpected_token(char *token)
{
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	return (-1);
}

int	parse_single_quote(t_cursor *s, t_chr_arr *token)
{
	char	c;

	forward_cursor(s);
	while (1)
	{
		c = peek_cursor(s);
		if (c == '\'')
			break ;
		if (!c)
			return (unexpected_eof_matching_error('\''));
		else
			push_chr_array(token, forward_cursor(s));
	}
	forward_cursor(s);
	return (0);
}

int	parse_double_quote(t_cursor *s, t_chr_arr *token)
{
	char	c;

	forward_cursor(s);
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (c == '\"')
			break ;
		else if (!c)
			return (unexpected_eof_matching_error('\"'));
		else
			push_chr_array(token, forward_cursor(s));
	}
	forward_cursor(s);
	return (0);
}

void	trim_whitespace(t_cursor *s, int expand_env)
{
	char	c;

	while (1)
	{
		if (expand_env)
			c = peek_cursor_with_env(s);
		else
			c = peek_cursor(s);
		if (!c || !ft_isspace(c))
			break ;
		else
			forward_cursor(s);
	}
}

t_token	*parse_next_token(t_cursor *s)
{
	t_token		*ret;
	t_chr_arr	*token;
	char		c;
	int			pushed;

	trim_whitespace(s, 1);
	if (!peek_cursor(s))
		return (NULL);
	ret = malloc(sizeof(t_token));
	ret->s = NULL;
	ret->type = SP_NONE;
	if (is_special(s, peek_cursor(s)))
	{
		ret->type = check_special_type(s);
		return (ret);
	}
	token = new_chr_array();
	pushed = 0;
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (!c || ft_isspace(c) || is_special(s, c))
			break ;
		pushed = 1;
		if (c == '\'')
			parse_single_quote(s, token);
		else if (c == '\"')
			parse_double_quote(s, token);
		else
			push_chr_array(token, forward_cursor(s));
	}
	if (pushed)
		ret->s = copy_chr_arr_to_string(token);
	else
	{
		free(ret);
		ret = NULL;
	}
	delete_chr_array(token);
	return (ret);
}


int	parse_next_token_internal(t_token *ret, t_cursor *s)
{
	t_chr_arr	*token;
	char		c;
	int			ended;

	trim_whitespace(s, 1);
	if (!peek_cursor(s))
		return (1);
	if (is_special(s, peek_cursor(s)))
	{
		ret->type = check_special_type(s);
		return (0);
	}
	token = new_chr_array();
	ended = 1;
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (!c || ft_isspace(c) || is_special(s, c))
			break ;
		ended = 0;
		if (c == '\'')
		{
			if (parse_single_quote(s, token) == -1)
			{
				delete_chr_array(token);
				return (-1);
			}
		}
		else if (c == '\"')
		{
			if (parse_double_quote(s, token) == -1)
			{
				delete_chr_array(token);
				return (-1);
			}
		}
		else
			push_chr_array(token, forward_cursor(s));
	}
	if (!ended)
		ret->s = copy_chr_arr_to_string(token);
	delete_chr_array(token);
	return (ended);
}


t_io_file	make_io_file(t_special_type type, char *s/*move ownership*/)
{
	t_io_file	ret;

	ret.fd = -1;
	ret.str = s;
	if (type == SP_IN)
	{
		ret.type = IO_IN_FILE;
	}
	else if (type == SP_IN_HEREDOC)
	{
		ret.type = IO_IN_HEREDOC;
		ret.fd = open_in_heredoc(ret.str);
	}
	else if (type == SP_OUT)
	{
		ret.type = IO_OUT_TRUNC;
	}
	else if (type == SP_OUT_APPEND)
	{
		ret.type = IO_OUT_APPEND;
	}
	return (ret);
}

t_parse_result	parse_single_command_(t_cursor *s, t_str_arr *args, t_io_arr *io)
{
	t_token	*token;
	t_token	*tmp;

	while (1)
	{
		token = parse_next_token(s);
		if (!token)
			return (RES_END);
		if (token->type == SP_PIPE)
		{
			free(token);
			return (RES_PIPE) ;
		}
		else if (token->type == SP_IN || token->type == SP_IN_HEREDOC
			|| token->type == SP_OUT || token->type == SP_OUT_APPEND)
		{
			tmp = parse_next_token(s);
			if (tmp->type != SP_NONE)
				syntax_error_unexpected_token("");
			t_io_file tmpfile = make_io_file(token->type, tmp->s);
			push_io_array(io, tmpfile);
			free(tmp);
			free(token);
		}
		else
		{
			push_str_array(args, token->s);
			free(token);
		}
	}
	return (RES_ERROR);
}

char	*token_type_to_str(t_special_type type)
{
	if (type == SP_IN)
		return ("<");
	if (type == SP_IN_HEREDOC)
		return ("<<");
	if (type == SP_OUT)
		return (">");
	if (type == SP_OUT_APPEND)
		return (">>");
	if (type == SP_PIPE)
		return ("|");
	return ("");
}

t_parse_result	parse_single_command(t_cursor *s, t_str_arr *args, t_io_arr *io)
{
	int		ret;
	t_token	token;
	t_token	tmp;

	while (1)
	{
		token.s = NULL;
		token.type = SP_NONE;
		ret = parse_next_token_internal(&token, s);
		if (ret == 1)
			return (RES_END);
		else if (ret == -1)
			return (RES_ERROR);
		if (token.type == SP_PIPE)
			return (RES_PIPE);
		else if (token.type == SP_IN || token.type == SP_IN_HEREDOC
			|| token.type == SP_OUT || token.type == SP_OUT_APPEND)
		{
			tmp.s = NULL;
			tmp.type = SP_NONE;
			ret = parse_next_token_internal(&tmp, s);
			if (ret == -1)
				return (RES_ERROR);
			else if (ret == 1 || tmp.type != SP_NONE)
			{
				syntax_error_unexpected_token(token_type_to_str(tmp.type));
				return (RES_ERROR);
			}
			push_io_array(io, make_io_file(token.type, tmp.s));
		}
		else
			push_str_array(args, token.s);
	}
	return (RES_ERROR);
}

int	parse_line_internal(t_cmd_arr *cmds, t_cursor *s)
{
	t_command		tmp_cmd;
	t_parse_result	parse_result;
	t_parse_result	last_result;

	last_result = RES_START;
	while (1)
	{
		init_command(&tmp_cmd);
		parse_result = parse_single_command(s, tmp_cmd.token, tmp_cmd.io);
		if (parse_result == RES_ERROR)
		{
			destruct_command(&tmp_cmd);
			return (-1);
		}
		else if (tmp_cmd.io->size == 0 && tmp_cmd.token->size == 0)
		{
			destruct_command(&tmp_cmd);
			if (parse_result == RES_PIPE)
				return (syntax_error_unexpected_token("|"));
			else if (last_result == RES_PIPE)
				return (syntax_error_unexpected_eof());
			break ;
		}
		else
			push_cmd_array(cmds, tmp_cmd);
		last_result = parse_result;
		if (parse_result == RES_END)
			break ;
	}
	return (0);
}


t_cmd_arr	*parse_line(char *line)
{
	t_cursor	s;
	t_cmd_arr	*cmds;

	init_cursor(&s, line);
	cmds = new_cmd_array();
	if (parse_line_internal(cmds, &s) == -1)
	{
		delete_cmd_array(cmds);
		cmds = NULL;
	}
	destruct_cursor(&s);
	return (cmds);
}

t_cmd_arr	*parse_line_(char *line)
{
	t_cursor		s;
	t_cmd_arr		*cmds;
	t_command		tmp_cmd;
	t_parse_result	parse_result;
	t_parse_result	last_result;

	init_cursor(&s, line);
	cmds = new_cmd_array();
	last_result = RES_START;
	while (1)
	{
		init_command(&tmp_cmd);
		parse_result = parse_single_command(&s, tmp_cmd.token, tmp_cmd.io);
		if (last_result == RES_PIPE
			&& tmp_cmd.io->size == 0 && tmp_cmd.token->size == 0)
		{
			if (parse_result == RES_END)
				syntax_error_unexpected_eof();
			else
				syntax_error_unexpected_token("|");
		}
		else if (last_result == RES_END
			&& tmp_cmd.io->size == 0 && tmp_cmd.token->size == 0)
			;
		else
			push_cmd_array(cmds, tmp_cmd);
		last_result = parse_result;
		if (parse_result == RES_END)
		{
			break ;
		}
	}
	destruct_cursor(&s);
	return (cmds);
}

int	check_command_nonempty(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (!ft_isspace(line[idx]))
			return (1);
		idx++;
	}
	return (0);
}
