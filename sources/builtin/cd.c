/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:26:14 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 13:12:28 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"

int	run_cd(char **argv)
{
    int     result;
        
    if (argv[1] && argv[2] && argv[3])
    {
        ft_putstr_fd("cd: too many arguments\n",2);
        return (1);
    }
    else if (argv[1] && (ft_strcmp(argv[1], "--") == 0 || ft_strcmp(argv[1], "~") == 0))
        result = change_dir("HOME");
    else if (!argv[1])
        result = change_dir("HOME");
    else if (argv[1] && ft_strcmp(argv[1], "-") == 0)
        result = change_dir("OLDPWD");
    else
        result = change_dir(argv[1]);
    return (result);
}

static int change_dir(char *path)
{
    char    *result;
    int     code;
    char    *prev_pwd;

    if (ft_strcmp(path, "HOME") == 0)
        result = find_env_by_name("HOME");
    else if (ft_strcmp(path, "OLDPWD") == 0)
        result = find_env_by_name("OLDPWD");
    else
        result = path;
    prev_pwd = find_env_by_name("PWD");
    code = chdir(result);
    return (change_result(path, code, prev_pwd));
}

static int change_result(char *path, int code, char *prev_pwd)
{
    struct stat fileStat;
    char result[1024];

    if (code == 0)
    {
        // chdir 정상처리 -> OLDPWD ,PWD 수정
        getcwd(result, 1024);
        update_env_value("OLDPWD", prev_pwd);
        update_env_value("PWD", result);
        return (0);
    }
    else
    {
        // chdir 오류 발생 -> 오류코드에 따라 출력
        if (stat(path, &fileStat) == -1)
            ft_putstr_fd("cd: no such file or directory: ",2);
        else if (S_ISREG(fileStat.st_mode))
            ft_putstr_fd("cd: not a directory: ",2);
        ft_putstr_fd(path, 2);
        ft_putchar_fd('\n', 2);
        return (127); 
    }
}


void    update_env_value(char *name, char *value)
{
    t_env	*cur;

    cur = find_previous_by_name(name);
    cur = cur->next;
    if (cur == NULL)
        add_new_env(name, value);
    else
    {
        if (cur->value)
		{
			free(cur->value);
			if (value)
				cur->value = ft_strdup(value);
			else
				cur->value = 0;
		}
		else
		{
			if (value)
				cur->value = ft_strdup(value);
		}
    }
}

