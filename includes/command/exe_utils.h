/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 16:05:19 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_UTILS_H
# define EXE_UTILS_H

# include "command/command.h"

typedef struct s_io_fd
{
	int	in;
	int	out;
}	t_io_fd;


void	redirect_command_io(t_command *cmd);
void	run_non_builtin(t_command *cmd);
void	execute_pipe_internal(int n_cmds, t_command *cmds);

#endif
