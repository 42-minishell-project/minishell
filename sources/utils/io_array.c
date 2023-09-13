/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:17:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/io_array.h"
#include <stdlib.h>

t_io_arr	*new_io_array(void)
{
	t_io_arr	*ret;

	ret = malloc(sizeof(t_io_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = ft_calloc(ret->capa, sizeof(t_io_file));
	return (ret);
}

void	push_io_array(t_io_arr *arr, t_io_file value)
{
	t_io_file	*new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = ft_calloc(2 * arr->capa, sizeof(t_io_file));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(t_io_file));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	delete_io_array(t_io_arr *arr)
{
	int	idx;

	idx = 0;
	while (idx < arr->size)
	{
		free(arr->arr[idx].str);
		if (arr->arr[idx].type == IO_IN_HEREDOC)
			close(arr->arr[idx].fd);
		idx++;
	}
	free(arr->arr);
	free(arr);
}
