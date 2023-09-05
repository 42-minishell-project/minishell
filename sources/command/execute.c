/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:11:36 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/04 12:56:48 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "libft/libft.h"
#include "command/execute.h"
#include "command/env_path.h"
#include "command/open_io.h"
#include "command/exe_utils.h"
// #include "env/env_test.h"
#include "env/env.h"
#include "utils/utils.h"
#include "utils/error.h"

#include <stdlib.h>
#include <stdio.h>
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

void	execute_single_command(t_command *cmd)
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
	if (cmd->token->size > 0)
	{
		// printf("process %d: exe\n", getpid());

		exe = find_executable(cmd->token->arr[0]);
		// printf("process %d: token %s, exe %s\n", getpid(), cmd->token->arr[0], exe);
		if (execve(exe, cmd->token->arr, get_envp()) == -1)
			fatal_error("execve failed");
	}
	exit(0);
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

void	execute_pipe(int n_cmds, t_command *cmds)
{
	int		*pids;
	t_io_fd	*io;
	int		pipe_fd[2];
	int		idx;

	pids = malloc(n_cmds * sizeof(int));
	io = alloc_io_array(n_cmds);
	idx = 0;
	while (idx < n_cmds)
	{
		if (idx < n_cmds - 1)
		{
			if (pipe(pipe_fd) == -1)
				ft_memset(pipe_fd, -1, sizeof(int) * 2);
			io[idx].out = pipe_fd[1];
			io[idx + 1].in = pipe_fd[0];
		}
		pids[idx] = fork();
		if (pids[idx] == 0)
		{
			if (dup2(io[idx].in, STDIN_FILENO) == -1 
				|| dup2(io[idx].out, STDOUT_FILENO) == -1)
				fatal_error("dup2() failed");
			execute_single_command(&cmds[idx]);
		}
		close(io[idx].in);
		close(io[idx].out);
		idx++;
	}
	free(io);
	wait_subprocesses(n_cmds, pids);
	free(pids);
}

// TODO: exit code
void	execute_commands(t_cmd_arr *cmds)
{
	int	pid;

	if (cmds->size == 0)
		return ;
	else if (cmds->size == 1)
	{
		// TODO: handle builtins
		pid = fork();
		if (pid == 0)
			execute_single_command(&cmds->arr[0]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		pid = fork();
		// printf("pid %d\n", pid);
		if (pid == 0)
			execute_pipe(cmds->size, cmds->arr);
		waitpid(pid, NULL, 0);
	}
}
