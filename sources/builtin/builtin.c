/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/06 15:35:31 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"

t_builtin_func	init_builtin(t_command *arr)
{
	char **argv;

	argv = arr->token->arr;
	if (ft_strcmp(argv[0], "echo") == 0)
		return (run_echo);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (run_pwd);
	else if (ft_strcmp(argv[0], "cd") == 0)
		return (run_cd);
	else if (ft_strcmp(argv[0], "exit") == 0)
		return (run_exit);
	else if (ft_strcmp(argv[0], "env") == 0)
		return (run_env);
	else if (ft_strcmp(argv[0], "export") == 0)
		return (run_export);
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (run_unset);
	return (0);
}
