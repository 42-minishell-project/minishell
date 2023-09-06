/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:56:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 19:03:04 by yeohong          ###   ########.fr       */
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
			redirect_command_io(cmd);
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
		return (WEXITSTATUS(status));
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
	return (WEXITSTATUS(status));
}

// TODO: exit code
int	execute_commands(t_cmd_arr *cmds)
{
	int	pid;

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
