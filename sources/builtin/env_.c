/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:01:27 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:00:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "env/env.h"
#include "utils/utils.h"

int	run_env(int argc, char **argv)
{
	char	**envp;
	int		idx;

	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("env: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	envp = get_envp();
	idx = 0;
	while (envp[idx])
	{
		printf("%s\n", envp[idx]);
		idx++;
	}
	free_2d_str_array(envp);
	return (0);
}
