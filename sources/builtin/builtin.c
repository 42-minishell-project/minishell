/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/12 09:44:33 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "builtin/builtin.h"
#include "builtin/builtin_func.h"

t_builtin_func	find_builtin_func(const char *name)
{
	if (!name)
		return (NULL);
	if (ft_strcmp(name, "echo") == 0)
		return (run_echo);
	else if (ft_strcmp(name, "pwd") == 0)
		return (run_pwd);
	else if (ft_strcmp(name, "cd") == 0)
		return (run_cd);
	else if (ft_strcmp(name, "exit") == 0)
		return (run_exit);
	else if (ft_strcmp(name, "env") == 0)
		return (run_env);
	else if (ft_strcmp(name, "export") == 0)
		return (run_export);
	else if (ft_strcmp(name, "unset") == 0)
		return (run_unset);
	return (NULL);
}
