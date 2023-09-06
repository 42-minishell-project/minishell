/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:46:19 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/06 19:11:30 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ERROR_H
# define BUILTIN_ERROR_H

int		builtin_error(char *type, char *path, char *message, int error_code);
void	print_export_error(char *str);
void	print_export_correct(char *name, char *value);

#endif
