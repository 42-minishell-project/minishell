/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/03 14:32:21 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"

int	init_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (run_echo(argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (run_pwd());
	else if (ft_strcmp(argv[0], "cd") == 0)
		return (run_cd(argv));
	return (0);
}
