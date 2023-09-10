/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:49:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:53:34 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "command/command.h"
# include "utils/cmd_array.h"

int	execute_commands(t_cmd_arr *commands);

extern int	g_child_pid;

#endif
