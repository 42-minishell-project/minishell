/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:04:37 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 14:41:36 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	alloc_expand(char **buffer, int size, int new_size)
{
	char	*new_buffer;

	new_buffer = (char *)malloc(sizeof(char) * new_size);
	if (new_buffer)
		ft_memcpy(new_buffer, *buffer, size);
	free(*buffer);
	*buffer = new_buffer;
}

static int	ft_readline_internal(int fd, char *buffer, int size)
{
	char	c;
	int		idx;
	int		n_bytes;

	idx = 0;
	while (1)
	{
		n_bytes = read(fd, &c, 1);
		if (n_bytes == -1)
			return (-1);
		if ((n_bytes == 0) && (idx == 0))
			return (-1);
		if ((n_bytes == 0) || (c == '\n'))
			break ;
		if (idx >= size - 1)
		{
			alloc_expand(&buffer, size, size * 2);
			size *= 2;
		}
		buffer[idx] = c;
		idx++;
	}
	buffer[idx] = '\0';
	return (0);
}

char	*ft_readline(int fd)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * INIT_BUFFER_SIZE);
	if (!ret)
		return (0);
	if (ft_readline_internal(fd, ret, INIT_BUFFER_SIZE) == -1)
	{
		free(ret);
		return (0);
	}
	return (ret);
}
