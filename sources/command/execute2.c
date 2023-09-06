/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:59:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 17:26:32 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "command/command.h"
#include "command/env_path.h"
#include "command/open_io.h"
#include "env/env.h"
#include "utils/io_array.h"
#include "utils/error.h"

void	prepare_io(t_io_arr *io, int *in_fd, int *out_fd)
{
	int			idx;
	t_io_type	type;

	idx = 0;
	while (idx < io->size)
	{
		type = io->arr[idx].type;
		if (type == IO_IN_FILE || type == IO_IN_HEREDOC)
		{
			close(*in_fd);
			if (type == IO_IN_FILE)
				*in_fd = open_in_file(io->arr[idx].str);
			else
				*in_fd = io->arr[idx].fd;
		}
		if (type == IO_OUT_TRUNC || type == IO_OUT_APPEND)
		{
			close(*out_fd);
			if (type == IO_OUT_TRUNC)
				*out_fd = open_out_file(io->arr[idx].str);
			else
				*out_fd = open_out_file_append(io->arr[idx].str);
		}
		idx++;
	}
}

void	redirect_command_io(t_command *cmd)
{
	/*should be called in subprocess*/
	char	*exe;
	int		in_fd;
	int		out_fd;

	// printf("process %d: token %d %s\n", getpid(), cmd->token->size, cmd->token->arr[0]);
	in_fd = STDIN_FILENO;
	out_fd = STDOUT_FILENO;
	prepare_io(cmd->io, &in_fd, &out_fd);
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
		fatal_error("dup2() failed");
	// close(in_fd);
	// close(out_fd);
}

void	run_non_builtin(t_command *cmd)
{
	char	*exe;

	redirect_command_io(cmd);
	if (cmd->token->size > 0)
	{
		exe = find_executable(cmd->token->arr[0]);
		if (execve(exe, cmd->token->arr, get_envp()) == -1)
			fatal_error("execve failed");
	}
	exit(0);
}
