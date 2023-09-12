/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:29:57 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 09:30:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNC_H
# define BUILTIN_FUNC_H

int	run_echo(int argc, char **argv);
int	run_pwd(int argc, char **argv);
int	run_cd(int argc, char **argv);
int	run_env(int argc, char **argv);
int	run_export(int argc, char **argv);
int	run_unset(int argc, char **argv);
int	run_exit(int argc, char **argv);

#endif
