/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/30 20:48:13 by hong-yeongh      ###   ########.fr       */
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
