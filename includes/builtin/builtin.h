/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 12:50:45 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

#include "env/env.h"
#include "env/env_utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int	init_builtin(char **argv);

// echo.c
int	run_echo(char **argv);
static int find_n_index(char **argv, int *n_flag);
static int	check_n_option(char *str);
static int check_minus(char *str);

// pwd.c
int	run_pwd(void);

// cd.c
int	    run_cd(char **argv);
static int     change_dir(char *path);
static int     change_result(char *path, int code, char *prev_pwd);
void     update_env_value(char *name, char *value);



#endif