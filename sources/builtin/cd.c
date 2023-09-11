/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:26:14 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 16:11:03 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/builtin_error.h"
#include "env/env.h"

static int	change_result(char *path, int code, char *prev_pwd)
{
	char	result[1024];
	int		error_code;

	if (code == 0)
	{
		getcwd(result, 1024);
		update_env("OLDPWD", prev_pwd);
		update_env("PWD", result);
		return (0);
	}
	else
	{
		builtin_error("cd", path);
		return (1);
	}
}

static int	change_dir(char *path)
{
	char	*result;
	int		code;
	char	*prev_pwd;

	prev_pwd = find_env("PWD");
	code = chdir(path);
	return (change_result(path, code, prev_pwd));
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
