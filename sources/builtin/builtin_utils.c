/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:49:10 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:12:17 by jimlee           ###   ########.fr       */
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

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9') && !ft_isdigit(str[i]))
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
