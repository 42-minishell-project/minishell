/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:46:19 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 14:39:27 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ERROR_H
# define BUILTIN_ERROR_H

void	builtin_error(char *type, char *message);
void	print_export_error(char *str);
void	print_export_correct(char *name, char *value);

#endif
