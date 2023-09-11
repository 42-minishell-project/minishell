/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:54:53 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ARRAY_H
# define STR_ARRAY_H

# include "utils/array_cfg.h"

typedef struct s_str_arr
{
	int		size;
	int		capa;
	char	**arr;
}	t_str_arr;

t_str_arr	*new_str_array(void);
void		delete_str_array(t_str_arr *arr);
void		push_str_array(t_str_arr *arr, char *s_freeable);
void		pop_str_array(t_str_arr *arr);

#endif
