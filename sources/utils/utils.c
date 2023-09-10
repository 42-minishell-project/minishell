/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:35:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:59:29 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strndup(const char *s, size_t n)
{
	int		size;
	char	*ret;

	size = n;
	if (ft_strlen(s) < n)
		size = ft_strlen(s);
	ret = malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s, size * sizeof(char));
	ret[size] = '\0';
	return (ret);
}

void	free_2d_str_array(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
