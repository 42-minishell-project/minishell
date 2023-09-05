/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 12:51:30 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"

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
