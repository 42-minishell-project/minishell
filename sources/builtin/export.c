/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:35:46 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/05 13:20:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env.h"
#include "utils/utils.h"

int	export(int argc, char **argv)
{
	int		idx;
	int		valid;
	char	*name;
	char	*value;

	valid = 0;
	idx = 1;
	while (idx < argc)
	{
		if (is_valid_identifier(argv[idx], &name, &value))
		{
			if (name && value)
				update_env(name, value);
			free(name);
			free(value);
		}
		else
		{
			ft_putstr_fd("export: `", STDERR_FILENO);
			ft_putstr_fd(argv[idx], STDERR_FILENO);
			ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
			valid = 1;
		}
		idx++;
	}
	return (valid);
}
