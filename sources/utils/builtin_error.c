/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:45:18 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 14:39:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

void	builtin_error(char *type, char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(type, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
}

void	print_export_error(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
}

void	print_export_correct(char *name, char *value)
{
	// ft_putstr_fd("declare -x ", 1);
	// ft_putstr_fd(name, 1);
	// ft_putstr_fd("=", 1);
	// ft_putchar_fd('\"', 1);
	// ft_putstr_fd(value, 1);
	// ft_putchar_fd('\"', 1);
	// ft_putchar_fd('\n', 1);
	printf("declare -x %s=\"%s\"\n", name, value);
}
