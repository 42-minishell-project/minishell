/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:10:11 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:08:31 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "command/command.h"
#include "command/execute.h"
#include "command/exec_utils.h"
#include "command/redirect.h"
#include "builtin/builtin.h"
#include "utils/error.h"

int	execute_single_builtin(t_command *cmd, t_builtin_func func)
{
	int	exit_code;
	int	old_stdin;
	int	old_stdout;

	old_stdin = dup(STDIN_FILENO);
	old_stdout = dup(STDOUT_FILENO);
	if (prepare_io_noexcept(cmd->io) == -1)
		exit_code = 1;
	else
		exit_code = func(cmd->token->size, cmd->token->arr);
	if (dup2(old_stdin, STDIN_FILENO) == -1
		|| dup2(old_stdout, STDOUT_FILENO) == -1)
		fatal_error("dup2() failed");
	close(old_stdin);
	close(old_stdout);
	return (exit_code);
}

int	execute_single_non_builtin(t_command *cmd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		run_non_builtin(cmd);
	}
	waitpid(pid, &status, 0);
	return (status_to_exit_code(status));
}

int	execute_single(t_command *cmd)
{
	t_builtin_func	func;

	func = NULL;
	if (cmd->token->size > 0)
		func = find_builtin_func(cmd->token->arr[0]);
	if (func)
	{
		return (execute_single_builtin(cmd, func));
	}
	else
	{
		return (execute_single_non_builtin(cmd));
	}
}
