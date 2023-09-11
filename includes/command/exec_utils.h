/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:01 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 18:23:34 by jimlee           ###   ########.fr       */
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
int		status_to_exit_code(int status);

#endif
