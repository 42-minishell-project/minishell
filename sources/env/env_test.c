/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:35:38 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/04 16:29:14 by yeohong          ###   ########.fr       */
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
