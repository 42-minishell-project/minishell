/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:25:55 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/02 11:19:18 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0'))
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (n == 0)
		return (0);
	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0') && (idx < n - 1))
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cptr;
	unsigned char	*s2_cptr;
	size_t			idx;

	if (n == 0)
		return (0);
	s1_cptr = (unsigned char *)s1;
	s2_cptr = (unsigned char *)s2;
	idx = 0;
	while ((s1_cptr[idx] == s2_cptr[idx]) && (idx < n - 1))
		idx++;
	return (s1_cptr[idx] - s2_cptr[idx]);
}
