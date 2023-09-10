/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:35:46 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 16:02:12 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env.h"
#include "utils/utils.h"
#include "utils/builtin_error.h"
#include <stdio.h>

static void	sorted_list(char **list, int size)
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
			if (ft_strncmp(list[j], list[j + 1], ft_strlen(list[j])) > 0)
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

static void	free_export(char *name, char *value, char **str)
{
	if (name)
		free(name);
	if (value)
		free(value);
	if (str)
		free_2d_str_array(str);
}

static void	print_export(void)
{
	char	**str;
	char	*name;
	char	*value;
	int		size;
	int		i;

	str = get_envp();
	size = 0;
	while (str[size])
		size++;
	i = 0;
	sorted_list(str, size);
	name = NULL;
	value = NULL;
	while (str[i])
	{
		parse_identifier(str[i], &name, &value);
		print_export_correct(name, value);
		i++;
	}
	free_export(name, value, str);
}

static int	run_one_export(int argc)
{
	if (argc == 1)
	{
		print_export();
		return (0);
	}
	return (1);
}

int	run_export(int argc, char **argv)
{
	int		idx;
	int		valid;
	char	*name;
	char	*value;

	valid = 0;
	idx = 1;
	if (run_one_export(argc) == 0)
		return (0);
	while (idx < argc)
	{
		if (parse_identifier(argv[idx], &name, &value))
		{
			if (name && value)
				update_env(name, value);
			free_export(name, value, 0);
		}
		else
		{
			print_export_error(argv[idx]);
			valid = 1;
		}
		idx++;
	}
	return (valid);
}
