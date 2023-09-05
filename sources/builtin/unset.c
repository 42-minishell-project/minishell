/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:05:39 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/05 13:25:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env.h"

int	unset(int argc, char **argv)
{
	int		idx;
	int		valid;
	char	*name;
	char	*value;

	valid = 0;
	idx = 1;
	while (idx < argc)
	{
		if (is_valid_identifier(argv[idx], NULL, NULL) == 1)
		{
			delete_env(argv[idx]);
		}
		else
		{
			ft_putstr_fd("env: `", STDERR_FILENO);
			ft_putstr_fd(argv[idx], STDERR_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
			valid = 1;
		}
		idx++;
	}
	return (valid);
}
