/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:36:09 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/12 17:57:42 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	while ((idx + 1 < size) && (src[idx] != '\0'))
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (size > 0)
		dest[idx] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest > size)
		return (size + len_src);
	idx = 0;
	while ((idx + len_dest + 1 < size) && (src[idx] != '\0'))
	{
		dest[idx + len_dest] = src[idx];
		idx++;
	}
	dest[idx + len_dest] = '\0';
	return (len_dest + len_src);
}
