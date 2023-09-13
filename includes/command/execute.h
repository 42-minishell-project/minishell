/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:49:41 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:05:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "utils/cmd_array.h"

int	execute_commands(t_cmd_arr *commands);

extern int	g_last_exit_code;

#endif
