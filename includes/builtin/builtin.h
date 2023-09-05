/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 13:51:42 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

int	init_builtin(char **argv);

// echo.c
int	run_echo(char **argv);
// static int find_n_index(char **argv, int *n_flag);
// static int	check_n_option(char *str);
// static int check_minus(char *str);

// pwd.c
int	run_pwd(void);

// cd.c
int	run_cd(char **argv);
// static int     change_dir(char *path);
// static int     change_result(char *path, int code, char *prev_pwd);



#endif
