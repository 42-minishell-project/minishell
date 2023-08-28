/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:58:44 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/23 15:19:29 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void	fatal_error(const char *message)
{
	// ft_putstr_fd(info()->exe, STDERR_FILENO);
	// ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(1);
}

void	command_find_error(const char *message)
{
	// ft_putstr_fd(info()->exe, STDERR_FILENO);
	// ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(127);
}

void	command_permission_error(const char *message)
{
	// ft_putstr_fd(info()->exe, STDERR_FILENO);
	// ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
	exit(126);
}

void	command_not_found_error(const char *command)
{
	// ft_putstr_fd(info()->exe, STDERR_FILENO);
	// ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd((char *)command, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}
