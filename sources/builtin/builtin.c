/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/01 17:04:34 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"

int	init_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (run_echo(argv));
	return (0);
}
