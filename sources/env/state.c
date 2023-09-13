/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:41:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:06:16 by jimlee           ###   ########.fr       */
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
}
