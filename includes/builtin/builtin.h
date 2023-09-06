/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/06 15:45:17 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

# include "command/command.h"

typedef int (*t_builtin_func)(t_command *);

t_builtin_func init_builtin(t_command *arr);

// echo.c
int	run_echo(int argc, char **argv);

// pwd.c
int	run_pwd(int argc, char **argv);

// cd.c
int	run_cd(int argc, char **argv);

// env_.c
int	run_env(int argc, char **argv);

// export.c
int	run_export(int argc, char **argv);

// unset.c
int	run_unset(int argc, char **argv);

// exit.c
int run_exit(int argc, char **argv);

#endif