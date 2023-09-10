/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:29:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 16:02:21 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command/command.h"

void	init_command(t_command *cmd)
{
	cmd->token = new_str_array();
	cmd->io = new_io_array();
}

void	destruct_command(t_command *cmd)
{
	delete_str_array(cmd->token);
	delete_io_array(cmd->io);
	cmd->token = NULL;
	cmd->io = NULL;
}
