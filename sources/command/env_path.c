/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:57:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 16:37:55 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "command/env_path.h"
#include "utils/utils.h"

char	***get_paths_ptr(void)
{
	static char	**paths;

	return (&paths);
}

char	**get_paths(void)
{
	return (*get_paths_ptr());
}

char	**parse_env_path(char **envp)
{
	char	*path;
	int		path_idx;

	path_idx = 0;
	while (envp[path_idx] && (ft_strncmp(envp[path_idx], "PATH=", 5) != 0))
		path_idx++;
	if (envp[path_idx])
		path = envp[path_idx] + 5;
	else
		path = "";
	return (ft_split(path, ':'));
}

void	init_paths(char **envp)
{
	*get_paths_ptr() = parse_env_path(envp);
}

void	delete_paths(void)
{
	char	***paths_ptr;

	paths_ptr = get_paths_ptr();
	free_2d_str_array(*paths_ptr);
	*paths_ptr = NULL;
}
