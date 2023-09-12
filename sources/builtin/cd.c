/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:26:14 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/12 09:43:32 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "env/env.h"

void	print_cd_error(const char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	perror(message);
}

static int	change_dir(char *path)
{
	char	*pwd;
	char	result[1024];

	if (chdir(path) == 0)
	{
		pwd = find_env("PWD");
		if (pwd)
			update_env("OLDPWD", pwd);
		getcwd(result, 1024);
		update_env("PWD", result);
		return (0);
	}
	else
	{
		print_cd_error(path);
		return (1);
	}
}

int	change_dir_home(void)
{
	char	*home_dir;

	home_dir = find_env("HOME");
	if (!home_dir)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
		return (1);
	}
	return (change_dir(home_dir));
}

int	run_cd(int argc, char **argv)
{
	int	result;

	if (argc == 1)
		result = change_dir_home();
	else if (ft_strcmp(argv[1], "--") == 0 || ft_strcmp(argv[1], "~") == 0)
		result = change_dir_home();
	else
		result = change_dir(argv[1]);
	return (result);
}
