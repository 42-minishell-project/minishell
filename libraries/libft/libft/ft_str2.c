/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:09 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/08 20:08:28 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_src;
	size_t	len_substr;
	char	*substr;

	len_substr = 0;
	len_src = ft_strlen(s);
	while ((start + len_substr < len_src) && (len_substr < len))
		len_substr++;
	substr = (char *)malloc(sizeof(char) * (len_substr + 1));
	if (!substr)
		return (NULL);
	if (start < len_src)
		ft_strlcpy(substr, &s[start], len_substr + 1);
	else
		substr[0] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*joined;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, len_s1 + 1);
	ft_strlcat(joined, s2, len_s1 + len_s2 + 1);
	return (joined);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	len_trimmed;
	int		idx_pre;
	int		idx_suf;
	char	*trimmed;

	len_s1 = ft_strlen(s1);
	idx_pre = 0;
	idx_suf = len_s1;
	while ((s1[idx_pre] != '\0') && ft_strchr(set, s1[idx_pre]))
		idx_pre++;
	while ((idx_suf > idx_pre) && ft_strchr(set, s1[idx_suf - 1]))
		idx_suf--;
	len_trimmed = idx_suf - idx_pre;
	trimmed = (char *)malloc(sizeof(char) * (len_trimmed + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[idx_pre], len_trimmed + 1);
	return (trimmed);
}
