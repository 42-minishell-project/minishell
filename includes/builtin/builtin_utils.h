/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:48:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 09:55:21 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

void	print_identifier_error(char *type, char *str);

int		is_number(char *str);
int		check_long_num(char *str, int standard, int i, int sum);

#endif
