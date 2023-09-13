/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:49:10 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 16:59:01 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void	print_identifier_error(char *type, char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(type, STDERR_FILENO);
	ft_putstr_fd(": `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
}

int	is_number(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		flag = 1;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (flag == 1 && ft_isspace(str[i]))
			return (0);
		else
			flag = 0;
		if (!('0' <= str[i] && str[i] <= '9') && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_long_num(char *str, int standard, int i, int sum)
{
	if (i == 17 && str[i + 1])
	{
		if (sum > standard && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
		if (sum == standard && (str[i + 1] > '7' && str[i + 1] <= '9'))
			return (1);
	}
	return (0);
}
