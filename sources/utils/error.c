/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:58:44 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/05 14:31:14 by yeohong          ###   ########.fr       */
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
