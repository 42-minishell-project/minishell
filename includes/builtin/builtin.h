/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:14:55 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/01 16:42:16 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUILTIN_H
# define BUILTIN_H

int	init_builtin(char **argv);
int	run_echo(char **argv);
int find_n_index(char **argv, int *n_flag);
int	check_n_option(char *str);
int check_minus(char *str);
#endif