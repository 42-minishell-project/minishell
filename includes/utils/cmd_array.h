/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/23 14:41:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_ARRAY_H
# define CMD_ARRAY_H

# include "utils/array_cfg.h"
# include "command/command.h"

typedef struct s_cmd_arr
{
	int			size;
	int			capa;
	t_command	*arr;
}	t_cmd_arr;

t_cmd_arr	*new_cmd_array(void);
void		delete_cmd_array(t_cmd_arr *arr);
void		push_cmd_array(t_cmd_arr *arr, t_command value);

#endif
