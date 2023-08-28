/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:35:38 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/23 14:36:57 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env/env_test.h"

static char	***get_envp_ptr(void)
{
	static char	**envp;

	return (&envp);
}

char	**get_envp(void)
{
	return (*get_envp_ptr());
}

void	init_envp(char **envp)
{
	*get_envp_ptr() = envp;
}
