/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:43:56 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:16:32 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "utils/chr_array.h"

t_chr_arr	*new_chr_array(void)
{
	t_chr_arr	*ret;

	ret = malloc(sizeof(t_chr_arr));
	ret->capa = INITIAL_CAPA;
	ret->size = 0;
	ret->arr = ft_calloc(ret->capa + 1, sizeof(char));
	return (ret);
}

void	push_chr_array(t_chr_arr *arr, char value)
{
	char	*new_arr;

	if (arr->size == arr->capa)
	{
		new_arr = ft_calloc(2 * arr->capa + 1, sizeof(char));
		ft_memcpy(new_arr, arr->arr, arr->size * sizeof(char));
		free(arr->arr);
		arr->arr = new_arr;
		arr->capa *= 2;
	}
	arr->arr[arr->size] = value;
	arr->size++;
}

void	pop_chr_array(t_chr_arr *arr)
{
	if (arr->size)
	{
		arr->size--;
		arr->arr[arr->size] = '\0';
	}
}

void	delete_chr_array(t_chr_arr *arr)
{
	free(arr->arr);
	free(arr);
}

char	*copy_chr_arr_to_string(t_chr_arr *arr)
{
	char	*s;

	s = ft_strdup(arr->arr);
	return (s);
}
