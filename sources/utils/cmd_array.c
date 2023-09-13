/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:16:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/cmd_array.h"
#include <stdlib.h>

t_cmd_arr	*new_cmd_array(void)
{
	t_cmd_arr	*ret;

	ret = malloc(sizeof(t_cmd_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = ft_calloc(ret->capa, sizeof(t_command));
	return (ret);
}

void	push_cmd_array(t_cmd_arr *arr, t_command value)
{
	t_command	*new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = ft_calloc(2 * arr->capa, sizeof(t_command));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(t_command));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	delete_cmd_array(t_cmd_arr *arr)
{
	int	idx;

	idx = 0;
	while (idx < arr->size)
	{
		destruct_command(&arr->arr[idx]);
		idx++;
	}
	free(arr->arr);
	free(arr);
}
