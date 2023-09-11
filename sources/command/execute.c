/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:56:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 18:25:31 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "command/command.h"
#include "command/execute.h"
#include "command/exec_utils.h"

int	execute_pipe(int n_cmds, t_command *cmds)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		execute_pipe_internal(n_cmds, cmds);
	}
	g_child_pid = pid;
	waitpid(pid, &status, 0);
	g_child_pid = 0;
	return (status_to_exit_code(status));
}

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
