/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:11:36 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 16:02:50 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command/command.h"
#include "command/exe_utils.h"
#include "builtin/builtin.h"
#include "utils/cmd_array.h"
#include "utils/error.h"

void	execute_pipe_single(t_command *cmd)
{
	t_builtin_func	func;

	func = NULL;
	if (cmd->token->size > 0)
		func = init_builtin(cmd->token->arr[0]);
	if (func)
	{
		prepare_io(cmd->io);
		exit(func(cmd->token->size, cmd->token->arr));
	}
	else
	{
		run_non_builtin(cmd);
	}
}

t_io_fd	*alloc_io_array(int n_cmds)
{
	t_io_fd	*ret;
	int		idx;

	ret = malloc(n_cmds * sizeof(t_io_fd));
	idx = 0;
	while (idx < n_cmds)
	{
		ret[idx].in = -1;
		ret[idx].out = -1;
		idx++;
	}
	ret[0].in = STDIN_FILENO;
	ret[n_cmds - 1].out = STDOUT_FILENO;
	return (ret);
}

int	wait_subprocesses(int n_cmds, int *pids)
{
	int	pid;
	int	status;
	int	exit_code;
	int	idx;

	idx = 0;
	exit_code = -1;
	while (idx < n_cmds)
	{
		pid = waitpid(0, &status, 0);
		if (pid < 0)
			continue ;
		if (pid == pids[n_cmds -1])
			exit_code = WEXITSTATUS(status);
		idx++;
	}
	if (exit_code < 0)
		return (1);
	return (exit_code);
}

void	open_pipe(t_io_fd *io, int idx)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
	io[idx].out = pipe_fd[1];
	io[idx + 1].in = pipe_fd[0];
}

void	execute_pipe_internal(int n_cmds, t_command *cmds)
{
	int		*pids;
	t_io_fd	*io;
	int		idx;

	pids = malloc(n_cmds * sizeof(int));
	io = alloc_io_array(n_cmds);
	idx = 0;
	while (idx < n_cmds)
	{
		if (idx < n_cmds - 1)
			open_pipe(io, idx);
		pids[idx] = fork();
		if (pids[idx] == 0)
		{
			if (io[idx].in != STDIN_FILENO)
			{
				dup2(io[idx].in, STDIN_FILENO);
				close(io[idx].in);
			}
			if (io[idx].out != STDOUT_FILENO)
			{
				dup2(io[idx].out, STDOUT_FILENO);
				close(io[idx].out);
			}
			if (idx < n_cmds - 1)
				close(io[idx + 1].in);
			execute_pipe_single(&cmds[idx]);
		}
		close(io[idx].in);
		close(io[idx].out);
		idx++;
	}
	free(io);
	exit(wait_subprocesses(n_cmds, pids));
}
