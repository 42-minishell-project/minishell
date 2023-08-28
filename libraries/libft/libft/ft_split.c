/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:09 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/15 16:31:27 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_words(const char *s, char delimiter)
{
	int	idx;
	int	n_word;

	n_word = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		while (s[idx] == delimiter)
			idx++;
		if (s[idx] != '\0')
		{
			n_word++;
			while ((s[idx] != '\0') && (s[idx] != delimiter))
				idx++;
		}
	}
	return (n_word);
}

static int	alloc_word(const char *start, int *idx, char delimiter, char **out)
{
	int	length;

	length = 0;
	while ((start[length] != '\0') && (start[length] != delimiter))
		length++;
	*out = (char *)malloc(sizeof(char) * (length + 1));
	if (!(*out))
		return (-1);
	ft_strlcpy(*out, start, length + 1);
	*idx += length;
	return (length);
}

static void	*free_str_array(char **arr, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		idx;
	int		n_word;
	char	**ret;

	n_word = get_num_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (n_word + 1));
	if (!ret)
		return (NULL);
	n_word = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		while (s[idx] == c)
			idx++;
		if (s[idx] != '\0')
		{
			if (alloc_word(&s[idx], &idx, c, &ret[n_word]) == -1)
				return (free_str_array(ret, n_word));
			n_word++;
		}
	}
	ret[n_word] = NULL;
	return (ret);
}
