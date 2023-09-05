/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:01:36 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 13:06:15 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"

int	run_echo(char **argv)
{
	int	i;
	int	n_flag;

	n_flag = 0;
	if (!argv[1])
	{
		ft_putchar_fd('\n', 1);
		return (0);
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
	return (0);
}

static int find_n_index(char **argv, int *n_flag)
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

static int	check_n_option(char *str)
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

static int check_minus(char *str)
{
	if (ft_strcmp(str, "-") == 0)
		return (1);
	return (0);
}

