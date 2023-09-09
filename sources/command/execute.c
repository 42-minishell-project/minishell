/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:56:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/09 20:52:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "command/command.h"
#include "command/execute.h"
#include "command/exe_utils.h"
#include "builtin/builtin.h"
#include "utils/cmd_array.h"


#include <stdio.h>
int	execute_single(t_command *cmd)
{
	t_builtin_func	func;
	int				pid;
	int				status;

	func = NULL;
	if (cmd->token->size > 0)
		func = init_builtin(cmd->token->arr[0]);
	if (func)
	{
		pid = fork();
		if (pid == 0)
		{
			prepare_io(cmd->io);
			exit(0);
		}
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status))
			return (WEXITSTATUS(status));
		return (func(cmd->token->size, cmd->token->arr));
	}
	else
	{
		pid = fork();
		if (pid == 0)
			run_non_builtin(cmd);
		else
			g_child_pid = pid;
		waitpid(pid, &status, 0);
		g_child_pid = 0;
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (WTERMSIG(status) + 128);
	}
}

int	execute_pipe(int n_cmds, t_command *cmds)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		execute_pipe_internal(n_cmds, cmds);
	}
	else
		g_child_pid = pid;
	waitpid(pid, &status, 0);
	g_child_pid = 0;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (WTERMSIG(status) + 128);
}

// TODO: exit code
int	execute_commands(t_cmd_arr *cmds)
{
	if (cmds->size == 0)
		return (0);
	else if (cmds->size == 1)
	{
		return (execute_single(&cmds->arr[0]));
	}
	else
	{
		return (execute_pipe(cmds->size, cmds->arr));
	}
}
