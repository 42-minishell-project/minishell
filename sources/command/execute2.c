/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:59:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/09 20:50:34 by jimlee           ###   ########.fr       */
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

void	prepare_io(t_io_arr *io)
{
	int			idx;
	t_io_type	type;
	int			fd;

	idx = 0;
	while (idx < io->size)
	{
		type = io->arr[idx].type;
		if (type == IO_IN_FILE || type == IO_IN_HEREDOC)
		{
			if (type == IO_IN_FILE)
				fd = open_in_file(io->arr[idx].str);
			else
				fd = io->arr[idx].fd;
			if (dup2(fd, STDIN_FILENO) == -1)
				fatal_error("dup2() failed");
			close(fd);
		}
		if (type == IO_OUT_TRUNC || type == IO_OUT_APPEND)
		{
			// close(*out_fd);
			if (type == IO_OUT_TRUNC)
				fd = open_out_file(io->arr[idx].str);
			else
				fd = open_out_file_append(io->arr[idx].str);
			if (dup2(fd, STDOUT_FILENO) == -1)
				fatal_error("dup2() failed");
			close(fd);
		}
		idx++;
	}
}

void	run_non_builtin(t_command *cmd)
{
	char	*exe;

	prepare_io(cmd->io);
	if (cmd->token->size > 0)
	{
		exe = find_executable(cmd->token->arr[0]);
		if (execve(exe, cmd->token->arr, get_envp()) == -1)
			fatal_error("execve failed");
	}
	exit(0);
}
