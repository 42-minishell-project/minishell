/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:11:20 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/06 15:01:31 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"

// int	init_builtin(int argc, char **argv)
// int	init_builtin(t_command *cmd);
int (*)(int, char **) check_builtin(char *)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		// return (run_echo(argv));
		return (run_echo);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (run_pwd());
	else if (ft_strcmp(argv[0], "cd") == 0)
		return (run_cd(argv));
	else if (ft_strcmp(argv[0], "exit") == 0)
		return (run_cd(argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (run_env(argc, argv));
	else if (ft_strcmp(argv[0], "export") == 0)
		return (run_export(argc, argv));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (run_unset(argc, argv));
	return (NULL);
}
