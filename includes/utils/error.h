/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:18:30 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:54:41 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	fatal_error(const char *message);
void	command_find_error(const char *message);
void	command_permission_error(const char *message);
void	command_not_found_error(const char *command);
void	command_directory_error(const char *command);

#endif
