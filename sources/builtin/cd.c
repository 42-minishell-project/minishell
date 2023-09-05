/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:26:14 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 22:41:28 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/builtin_error.h"
#include "env/env.h"

static int change_result(char *path, int code, char *prev_pwd)
{
    char result[1024];
    int error_code;
    
    if (code == 0)
    {
        getcwd(result, 1024);
        update_env("OLDPWD", prev_pwd);
        update_env("PWD", result);
        return (0);
    }
    else
    {
        if (access(path, F_OK) == -1)
			error_code = print_builtin_error("cd", path, ": no such file or directory", 127);
		else if (access(path, R_OK) == -1)
			error_code = print_builtin_error("cd", path, ": permission denied", 126);
		else
			error_code = print_builtin_error("cd", path, ": not a directory", 127);
        return (error_code); 
    }
}

static int change_dir(char *path)
{
    char    *result;
    int     code;
    char    *prev_pwd;

    if (ft_strcmp(path, "HOME") == 0)
        result = find_env("HOME");
    else if (ft_strcmp(path, "OLDPWD") == 0)
        result = find_env("OLDPWD");
    else
        result = path;
    prev_pwd = find_env("PWD");
    code = chdir(result);
    return (change_result(path, code, prev_pwd));
}

int	run_cd(char **argv)
{
    int     result;
        
    if (argv[1] && (ft_strcmp(argv[1], "--") == 0 || ft_strcmp(argv[1], "~") == 0))
        result = change_dir("HOME");
    else if (!argv[1])
        result = change_dir("HOME");
    else if (argv[1] && ft_strcmp(argv[1], "-") == 0)
        result = change_dir("OLDPWD");
    else
        result = change_dir(argv[1]);
    return (result);
}
