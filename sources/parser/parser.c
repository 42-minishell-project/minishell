/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 18:27:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "parser/utils.h"
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
		c = peek_cursor_with_env(s);
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

t_parse_result	parse_next_token_internal(t_chr_arr *token, t_cursor *s)
{
	char			c;
	t_parse_result	ended;

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
				return (RES_ERROR);
		}
		else if (c == '\"')
		{
			if (parse_double_quote(s, token) == -1)
				return (RES_ERROR);
		}
		else
			push_chr_array(token, forward_cursor(s));
	}
	return (ended);
}

t_parse_result	parse_next_token(t_token *ret, t_cursor *s)
{
	t_chr_arr		*token;
	t_parse_result	result;

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
	result = parse_next_token_internal(token, s);
	if (result == RES_OK)
		ret->s = copy_chr_arr_to_string(token);
	delete_chr_array(token);
	return (result);
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
	// else if (type == SP_IN_HEREDOC)
	// {
	// 	ret.type = IO_IN_HEREDOC;
	// 	int code;
	// 	ret.fd = open_heredoc(ret.str, &code);
	// }
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

t_io_file	make_heredoc_from_token(t_token *token, int *exit_code)
{
	t_io_file	ret;

	ret.fd = open_heredoc(token->s, exit_code);
	ret.str = NULL;
	ret.type = IO_IN_HEREDOC;
	free(token->s);
	token->s = NULL;
	return (ret);
}

char	*io_token_type_to_str(t_special_type type)
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
	return ("newline");
}

int	parse_io_file(t_cursor *s, t_io_type type, t_io_arr *io)
{
	t_parse_result	ret;
	t_token			tmp;
	t_io_file		file;
	int				heredoc_exit_code;

	tmp.s = NULL;
	tmp.type = SP_NONE;
	ret = parse_next_token(&tmp, s);
	if (ret == RES_ERROR)
		return (2);
	else if (ret == RES_END || tmp.type != SP_NONE)
	{
		syntax_error_unexpected_token(io_token_type_to_str(tmp.type));
		return (2);
	}
	if (type == IO_IN_HEREDOC)
	{
		file = make_heredoc_from_token(&tmp, &heredoc_exit_code);
		if (heredoc_exit_code != 0)
			return (heredoc_exit_code);
	}
	else
		file = make_io_file(type, tmp.s);
	push_io_array(io, file);
	return (0);
}

t_command_end	parse_single_command(
	t_cursor *s, t_str_arr *args, t_io_arr *io, int *exit_code)
{
	t_parse_result	ret;
	t_token			token;

	while (1)
	{
		ret = parse_next_token(&token, s);
		if (ret == RES_END)
			return (CMD_END);
		else if (ret == RES_ERROR)
			return (CMD_ERROR);
		if (token.type == SP_PIPE)
			return (CMD_PIPE);
		else if (token.type == SP_IN || token.type == SP_IN_HEREDOC
			|| token.type == SP_OUT || token.type == SP_OUT_APPEND)
		{
			*exit_code = parse_io_file(s, token.type, io);
			if (*exit_code != 0)
				return (CMD_ERROR);
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

t_parse_result	parse_and_interpret(
	t_cursor *s, t_cmd_arr *cmds, t_command_end *last_result, int *exit_code)
{
	t_command	tmp_cmd;
	t_command_end	cmd_end;
	t_parse_result	result;

	init_command(&tmp_cmd);
	cmd_end = parse_single_command(s, tmp_cmd.token, tmp_cmd.io, exit_code);
	if (cmd_end == CMD_ERROR)
	{
		destruct_command(&tmp_cmd);
		return (RES_ERROR);
	}
	result = interpret_command_parsed(&tmp_cmd, cmd_end, *last_result);
	if (result != RES_OK)
	{
		destruct_command(&tmp_cmd);
		if (result == RES_ERROR)
		{
			*exit_code = 2;
			return (RES_ERROR);
		}
		return (RES_END);
	}
	*last_result = cmd_end;
	push_cmd_array(cmds, tmp_cmd);
	return (RES_OK);
}

int	parse_line_internal(t_cmd_arr *cmds, t_cursor *s)
{
	// t_command		tmp_cmd;
	t_parse_result	result;
	int				exit_code;
	t_command_end	last_result;

	last_result = CMD_START;
	while (1)
	{
		result = parse_and_interpret(s, cmds, &last_result, &exit_code);
		// printf("result %d, last_result %d\n", result, last_result);
		if (result == RES_ERROR)
			return (exit_code);
		if (result == RES_END)
			break ;
		// init_command(&tmp_cmd);
		// exit_code = 0;
		// parse_result = parse_single_command(
		// 	s, tmp_cmd.token, tmp_cmd.io, &exit_code);
		// if (parse_result == RES_ERROR)
		// {
		// 	destruct_command(&tmp_cmd);
		// 	return (exit_code);
		// }
		// result = interpret_command_parsed(&tmp_cmd, parse_result, last_result);
		// if (result != RES_OK)
		// {
		// 	destruct_command(&tmp_cmd);
		// 	if (result == RES_ERROR)
		// 		return (2);
		// 	break ;
		// }
		// push_cmd_array(cmds, tmp_cmd);
		// last_result = parse_result;
		// if (parse_result == CMD_END)
		// 	break ;
	}
	return (0);
}

// t_cmd_arr	*parse_line(char *line)
int	parse_line(char *line, t_cmd_arr *cmds)
{
	t_cursor	s;
	int			exit_code;
	// t_cmd_arr	*cmds;

	init_cursor(&s, line);
	// cmds = new_cmd_array();
	exit_code = parse_line_internal(cmds, &s);
	destruct_cursor(&s);
	return (exit_code);
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
