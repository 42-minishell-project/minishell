/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:28:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:14:03 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "utils/str_array.h"
# include "utils/io_array.h"

typedef struct s_command
{
	t_str_arr	*token;
	t_io_arr	*io;
}	t_command;

void	init_command(t_command *cmd);
void	destruct_command(t_command *cmd);

#endif
