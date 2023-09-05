/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 22:52:03 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

int	init_builtin(int argc, char **argv);

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