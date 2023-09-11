/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:59:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 17:07:43 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"
#include "command/command.h"
#include "command/exec_utils.h"
#include "command/redirect.h"
#include "env/env.h"
#include "utils/error.h"

char	*find_path_prefix(char *exe, char **paths)
{
	char	*full_path;
	int		exec_len;
	int		path_len;
	int		idx;

	idx = 0;
	exec_len = ft_strlen(exe);
	while (paths && paths[idx])
	{
		path_len = ft_strlen(paths[idx]);
		full_path = ft_calloc(path_len + exec_len + 2, sizeof(char));
		ft_memcpy(full_path, paths[idx], path_len);
		full_path[path_len] = '/';
		ft_memcpy(full_path + path_len + 1, exe, exec_len);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		idx++;
	}
	return (NULL);
}

char	*find_executable(char *exe)
{
	char		*exe_path;
	struct stat	buf;

	if (ft_strlen(exe) == 0)
		command_not_found_error(exe);
	else if (ft_strchr(exe, '/'))
		exe = ft_strdup(exe);
	else
	{
		exe_path = find_path_prefix(exe, get_env_path());
		if (!exe_path)
			command_not_found_error(exe);
		exe = exe_path;
	}
	if (access(exe, F_OK) == -1)
		command_find_error(exe);
	if (access(exe, X_OK) == -1)
		command_permission_error(exe);
	if (stat(exe, &buf) == -1)
		fatal_error(exe);
	if (S_ISDIR(buf.st_mode))
		command_directory_error(exe);
	return (exe);
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

int	status_to_exit_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (WTERMSIG(status) + 128);
}
