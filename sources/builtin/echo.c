/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:01:36 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/01 17:52:32 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"

int	run_echo(char **argv)
{
	int	i;
	int	n_flag;

	n_flag = 0;
	if (!argv[1])
	{
		ft_putchar_fd('\n', 1);
		return (1);
	}
	i = find_n_index(argv, &n_flag);
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		i++;
		if (argv[i])
			ft_putchar_fd(' ', 1);
	}
	if (n_flag == 0)
		ft_putchar_fd('\n', 1);
	return (1);
}

int find_n_index(char **argv, int *n_flag)
{
	int	i;
	int	result;
	
	i = 1;
	if (check_minus(argv[i]))
		return (i + 1);
	while (argv[i])
	{
		result = check_n_option(argv[i]);
		if (result == 0)
			return (i);
		if (*n_flag == 0 && result == 1)
			*n_flag = 1;
		i++;
	}
	return (i);
}

int	check_n_option(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int check_minus(char *str)
{
	if (ft_strcmp(str, "-") == 0)
		return (1);
	return (0);
}

