/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:52 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:45:42 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	put_n_times(char c, int n)
{
	int	times;

	times = 0;
	while (times < n)
	{
		if (ft_putchar(c) == -1)
			return (-1);
		times++;
	}
	return (n);
}
