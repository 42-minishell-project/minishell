/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:16:51 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/12 17:41:31 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 0x20);
	else
		return (c);
}

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 0x20);
	else
		return (c);
}

char	*ft_strchr(const char *s, int c)
{
	int	idx;
	int	len_s;

	idx = 0;
	len_s = ft_strlen(s);
	while (idx <= len_s)
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = ft_strlen(s);
	while (idx >= 0)
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx--;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cptr;
	size_t	idx;

	s_cptr = (char *)s;
	idx = 0;
	while (idx < n)
	{
		if (s_cptr[idx] == (char)c)
			return ((void *)&s_cptr[idx]);
		idx++;
	}
	return (NULL);
}
