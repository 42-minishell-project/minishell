/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:02:16 by hong-yeongh       #+#    #+#             */
/*   Updated: 2023/09/01 17:02:30 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

int	run_echo(char **argv);
int find_n_index(char **argv, int *n_flag);
int	check_n_option(char *str);
int check_minus(char *str);

#endif