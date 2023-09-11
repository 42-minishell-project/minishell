/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:31:51 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 16:17:47 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/cursor.h"

char	peek_cursor(t_cursor *cursor)
{
	if (!cursor->cur)
		return ('\0');
	return (*cursor->cur->ptr);
}

char	forward_cursor(t_cursor *cursor)
{
	char	c;
	t_node	*tmp;

	if (!cursor->cur)
		return ('\0');
	c = *cursor->cur->ptr;
	cursor->cur->ptr++;
	if (*cursor->cur->ptr == '\0' || *cursor->cur->ptr == cursor->cur->end)
	{
		tmp = cursor->cur;
		cursor->cur = cursor->cur->prev;
		if (tmp->flag & CURSOR_OWNERSHIP)
			free(tmp->start);
		free(tmp);
	}
	return (c);
}
