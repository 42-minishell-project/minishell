/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:17:15 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/str_array.h"
#include <stdlib.h>

t_str_arr	*new_str_array(void)
{
	t_str_arr	*ret;

	ret = malloc(sizeof(t_str_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = ft_calloc(ret->capa + 1, sizeof(char *));
	return (ret);
}

void	push_str_array(t_str_arr *arr, char *value)
{
	char	**new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = ft_calloc(2 * arr->capa + 1, sizeof(char *));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(char *));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	pop_str_array(t_str_arr *arr)
{
	if (arr->size)
	{
		free(arr->arr[arr->size - 1]);
		arr->size--;
	}
}

void	delete_str_array(t_str_arr *arr)
{
	int	idx;

	idx = 0;
	while (idx < arr->size)
	{
		free(arr->arr[idx]);
		idx++;
	}
	free(arr->arr);
	free(arr);
}
