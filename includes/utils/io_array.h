/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:54:47 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_ARRAY_H
# define IO_ARRAY_H

# include "utils/array_cfg.h"
# include "parser/io_file.h"

typedef struct s_io_arr
{
	int			size;
	int			capa;
	t_io_file	*arr;
}	t_io_arr;

t_io_arr	*new_io_array(void);
void		delete_io_array(t_io_arr *arr);
void		push_io_array(t_io_arr *arr, t_io_file value);

#endif
