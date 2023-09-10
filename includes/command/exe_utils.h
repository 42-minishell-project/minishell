/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:53:29 by yeohong          ###   ########.fr       */
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

void	prepare_io(t_io_arr *cmd);
void	run_non_builtin(t_command *cmd);
void	execute_pipe_internal(int n_cmds, t_command *cmds);
int		prepare_io_noexcept(t_io_arr *io);

#endif
