/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:45:18 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/06 19:11:32 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	builtin_error(char *type, char *path, char *message, int error_code)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	return (error_code);
}

void	print_export_error(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
}

void	print_export_correct(char *name, char *value)
{
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd("=", 1);
	ft_putchar_fd('\"', 1);
	ft_putstr_fd(value, 1);
	ft_putchar_fd('\"', 1);
	ft_putchar_fd('\n', 1);
}
