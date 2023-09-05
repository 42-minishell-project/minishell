/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 15:08:31 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

int	init_builtin(char **argv);

// echo.c
int	run_echo(char **argv);

// pwd.c
int	run_pwd(void);

// cd.c
int	run_cd(char **argv);
static int     change_dir(char *path);
static int     change_result(char *path, int code, char *prev_pwd);



#endif
