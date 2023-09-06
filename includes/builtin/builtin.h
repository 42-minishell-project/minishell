/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/06 15:23:49 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

# include "command/command.h"
//typedef int (*t_builtin_func)(int, char **);

//t_builtin_func init_builtin(t_comm_);

//int	init_builtin(int argc, char **argv);
int	init_builtin(t_command *arr);

// echo.c
int	run_echo(char **argv);

// pwd.c
int	run_pwd(void);

// cd.c
int	run_cd(char **argv);

// env_.c
int	run_env(int argc, char **argv);

// export.c
int	run_export(int argc, char **argv);

// unset.c
int	run_unset(int argc, char **argv);

// exit.c
int run_exit(int argc, char **argv);

#endif