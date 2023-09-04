/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:33:54 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/01 17:59:40 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"

int	run_pwd(void)
{
    char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		return (-1);
    ft_putstr_fd(path, 1);
    ft_putchar_fd('\n', 1);
	free(path);
	path = NULL;
    return (1);
}
