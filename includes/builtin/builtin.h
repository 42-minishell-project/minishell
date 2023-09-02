/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/02 16:57:11 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

#include "libft/libft.h"
#include "env/env.h"
#include "env/env_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int	init_builtin(char **argv);

// echo.c
int	run_echo(char **argv);
int find_n_index(char **argv, int *n_flag);
int	check_n_option(char *str);
int check_minus(char *str);

// pwd.c
int	run_pwd(void);

// cd.c
int	run_cd(char **argv);
int change_dir(char *path);
int change_result(char *path, int code);



#endif