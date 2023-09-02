/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:26:14 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/02 16:33:12 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"

int	run_cd(char **argv)
{
    char    *home_path;
    int     result;

    if (argv[1] && argv[2] && argv[3])
    {
        ft_putstr_fd("cd: too many arguments\n",2);
        return (1);
    }
    else if (!argv[1] | ft_strcmp(argv[1], "--") == 0 | ft_strcmp(argv[1], "~") == 0)
        result = change_dir("HOME");
    else
        result = change_dir(argv[1]);
    return (1);
}
// HOMe환경변수 없을때 보기
// 옮기고 나서 PWD, OLDPWD확인

int change_dir(char *path)
{
    char    *result;
    int     code;
    
    if (ft_strcmp(path, "HOME") == 0)
        result = find_env_by_name("HOME");
    else if (ft_strcmp(path, "OLDPWD") == 0)
        result = find_env_by_name("OLDPWD");
    else
        result = path;
    code = chdir(result);
    return (change_result(path, code));
    
}

int change_result(char *path, int code)
{
    struct stat fileStat;

    if (code == 0)
    {
        // chdir 정상처리 -> OLDPWD ,PWD 수정
        
    }
    else
    {
        // chdir 오류 발생 -> 오류코드에 따라 출력
        if (stat(path, &fileStat) == -1)
            ft_putstr_fd("cd: no such file or directory: ",2);
        else if (S_ISREG(fileStat.st_mode))
            ft_putstr_fd("cd: not a directory: ",2);
        ft_putstr_fd(path, 2);
        return (1); 
    }
}


