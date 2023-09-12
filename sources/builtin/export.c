/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:35:46 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 09:49:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "builtin/builtin_utils.h"
#include "env/env.h"
#include "utils/utils.h"

static void	sort_list(char **list, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(list[j], list[j + 1]) > 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	print_envvar_list(void)
{
	char	**envp;
	char	*name;
	char	*value;
	int		size;
	int		i;

	envp = get_envp();
	size = 0;
	while (envp[size])
		size++;
	sort_list(envp, size);
	i = 0;
	while (envp[i])
	{
		parse_identifier(envp[i], &name, &value);
		if (name && value)
			printf("declare -x %s=\"%s\"\n", name, value);
		free(name);
		free(value);
		i++;
	}
	free_2d_str_array(envp);
}

int	export_identifers(int n_ids, char **identifiers)
{
	int		exit_code;
	int		idx;
	char	*name;
	char	*value;

	exit_code = 0;
	idx = 0;
	while (idx < n_ids)
	{
		if (parse_identifier(identifiers[idx], &name, &value))
		{
			if (name && value)
				update_env(name, value);
			free(name);
			free(value);
		}
		else
		{
			print_identifier_error("export", identifiers[idx]);
			exit_code = 1;
		}
		idx++;
	}
	return (exit_code);
}

int	run_export(int argc, char **argv)
{
	if (argc == 1)
	{
		print_envvar_list();
		return (0);
	}
	else
		return (export_identifers(argc - 1, &argv[1]));
}
