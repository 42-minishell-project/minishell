/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:53:42 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 14:56:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"
// #include "command/env_path.h"
#include "env/env.h"
#include "utils/error.h"

char	*find_path_prefix(char *exe, char **paths)
{
	int		idx;
	char	*full_path;
	size_t	exec_len;
	size_t	path_len;

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
	char	*exe_path;
	struct stat	buf;

	if ((ft_strlen(exe) == 0) || ft_strchr(exe, '/'))
	{
		exe = ft_strdup(exe);
	}
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
