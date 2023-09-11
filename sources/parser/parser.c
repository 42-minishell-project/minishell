/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 16:36:37 by jimlee           ###   ########.fr       */
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
	// exit(1);
	return (-1);
}
int	syntax_error_unexpected_eof(void)
{
	printf("syntax error: unexpected end of file\n");
	// exit(1);
	return (-1);
}
int	syntax_error_unexpected_token(char *token)
{
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	// exit(1);
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


t_parse_result	parse_next_token_internal(t_token *ret, t_cursor *s)
{
	t_chr_arr		*token;
	char			c;
	t_parse_result	ended;

	ret->type = SP_NONE;
	ret->s = NULL;
	trim_whitespace(s, 1);
	if (!peek_cursor(s))
		return (RES_END);
	if (is_special(s, peek_cursor(s)))
	{
		ret->type = check_special_type(s);
		return (RES_OK);
	}
	token = new_chr_array();
	ended = RES_END;
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (!c || ft_isspace(c) || is_special(s, c))
			break ;
		ended = RES_OK;
		if (c == '\'')
		{
			if (parse_single_quote(s, token) == -1)
			{
				delete_chr_array(token);
				return (RES_ERROR);
			}
		}
		else if (c == '\"')
		{
			if (parse_double_quote(s, token) == -1)
			{
				delete_chr_array(token);
				return (RES_ERROR);
			}
		}
		else
			push_chr_array(token, forward_cursor(s));
	}
	if (ended == RES_OK)
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

t_command_end	parse_single_command(t_cursor *s, t_str_arr *args, t_io_arr *io)
{
	t_parse_result	ret;
	t_token			token;
	t_token			tmp;

	while (1)
	{
		ret = parse_next_token_internal(&token, s);
		if (ret == RES_END)
			return (CMD_END);
		else if (ret == RES_ERROR)
			return (CMD_ERROR);
		if (token.type == SP_PIPE)
			return (CMD_PIPE);
		else if (token.type == SP_IN || token.type == SP_IN_HEREDOC
			|| token.type == SP_OUT || token.type == SP_OUT_APPEND)
		{
			tmp.s = NULL;
			tmp.type = SP_NONE;
			ret = parse_next_token_internal(&tmp, s);
			if (ret == RES_ERROR)
				return (CMD_ERROR);
			else if (ret == RES_END || tmp.type != SP_NONE)
			{
				syntax_error_unexpected_token(token_type_to_str(tmp.type));
				return (CMD_ERROR);
			}
			push_io_array(io, make_io_file(token.type, tmp.s));
		}
		else
			push_str_array(args, token.s);
	}
	return (CMD_ERROR);
}

t_parse_result	interpret_command_parsed(
	t_command *cmd, t_command_end result, t_command_end last_result)
{
	if (result == CMD_ERROR)
	{
		return (RES_ERROR);
	}
	else if (cmd->io->size == 0 && cmd->token->size == 0)
	{
		if (result == CMD_PIPE)
		{
			syntax_error_unexpected_token("|");
			return (RES_ERROR);
		}
		else if (last_result == CMD_PIPE)
		{
			syntax_error_unexpected_eof();
			return (RES_ERROR);
		}
		return (RES_END);
	}
	return (RES_OK);
}

int	parse_line_internal(t_cmd_arr *cmds, t_cursor *s)
{
	t_command		tmp_cmd;
	t_command_end	parse_result;
	t_command_end	last_result;
	t_parse_result	result;

	last_result = CMD_START;
	while (1)
	{
		init_command(&tmp_cmd);
		parse_result = parse_single_command(s, tmp_cmd.token, tmp_cmd.io);
		result = interpret_command_parsed(&tmp_cmd, parse_result, last_result);
		if (result != RES_OK)
		{
			destruct_command(&tmp_cmd);
			if (result == RES_ERROR)
				return (-1);
			break ;
		}
		push_cmd_array(cmds, tmp_cmd);
		last_result = parse_result;
		if (parse_result == CMD_END)
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
