/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:49:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 16:07:07 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "command/command.h"
# include "utils/cmd_array.h"

void	execute_commands(t_cmd_arr *commands);
// void	execute_command(t_command *command);


extern int	g_child_pid;

#endif
