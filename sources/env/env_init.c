/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:54:28 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:03:10 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env/env.h"

void	init_envs(const char **envp)
{
	int		idx;
	char	*name;
	char	*value;

	idx = 0;
	while (envp[idx])
	{
		name = NULL;
		value = NULL;
		parse_identifier(envp[idx], &name, &value);
		if (name && value)
			update_env(name, value);
		free(name);
		free(value);
		idx++;
	}
	update_env_path(find_env("PATH"));
}
