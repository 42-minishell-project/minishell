/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:11:48 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:16:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parser/typedefs.h"
#include "parser/cursor.h"
#include "parser/parse_func.h"
#include "parser/parse_io.h"
#include "parser/parse_utils.h"
#include "parser/parse_error.h"
#include "utils/cmd_array.h"

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
	t_command		tmp_cmd;
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

int	parse_line(char *line, t_cmd_arr *cmds)
{
	t_cursor		s;
	int				exit_code;
	t_parse_result	result;
	t_command_end	last_result;

	init_cursor(&s, line);
	last_result = CMD_START;
	while (1)
	{
		result = parse_and_interpret(&s, cmds, &last_result, &exit_code);
		if (result == RES_ERROR)
		{
			break ;
		}
		if (result == RES_END)
		{
			exit_code = 0;
			break ;
		}
	}
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
