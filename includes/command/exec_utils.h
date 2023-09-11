/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:33:08 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_UTILS_H
# define EXEC_UTILS_H

# include "command/command.h"

typedef struct s_io_fd
{
	int	in;
	int	out;
}	t_io_fd;

void	execute_pipe_internal(int n_cmds, t_command *cmds);
int		execute_single(t_command *cmd);
void	run_non_builtin(t_command *cmd);

#endif
