/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/01 16:41:50 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"
#include <stdio.h>

int	init_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (run_echo(argv));
	return (0);
}

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
// -이 처음에 홀로 나오면 그냥 출력안함
// -n이 있고 뒤에 n으로 이루어졌으면 -n옵션
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

