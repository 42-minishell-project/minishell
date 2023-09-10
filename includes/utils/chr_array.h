/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:42:06 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:54:37 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHR_ARRAY_H
# define CHR_ARRAY_H

# include "utils/array_cfg.h"

typedef struct s_chr_arr
{
	int		size;
	int		capa;
	char	*arr;
}	t_chr_arr;

t_chr_arr	*new_chr_array(void);
void		delete_chr_array(t_chr_arr *arr);
void		push_chr_array(t_chr_arr *arr, char value);
void		pop_chr_array(t_chr_arr *arr);
char		*copy_chr_arr_to_string(t_chr_arr *arr);

#endif
