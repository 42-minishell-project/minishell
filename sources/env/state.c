/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:41:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 17:05:09 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/state.h"
#include "utils/utils.h"

t_env_state	*get_env_state(void)
{
	static t_env_state	state;

	return (&state);
}

char	**get_env_path(void)
{
	return (get_env_state()->paths);
}

#include <stdio.h>
void	update_env_path(char *path_str)
{
	t_env_state	*s;

	s = get_env_state();
	if (s->paths)
	{
		free_2d_str_array(s->paths);
		s->paths = NULL;
	}
	if (path_str)
		s->paths = ft_split(path_str, ':');

	if (s->paths)
	{
		printf("[PATH]:\n");
		for (int idx = 0; s->paths[idx]; idx++)
			printf("  %s\n", s->paths[idx]);
		printf("\n");
	}
	else
		printf("[PATH] is null\n");
}

char	*get_last_exit_code(void)
{
	t_env_state	*s;

	s = get_env_state();
	if (!s->exit_code_str)
		return ("0");
	return (s->exit_code_str);
}

void	update_last_exit_code(int exit_code)
{
	t_env_state	*s;

	s = get_env_state();
	if (s->exit_code_str)
		free(s->exit_code_str);
	s->exit_code_str = ft_itoa(exit_code);
}

