/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:31:51 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/14 10:17:16 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/cursor.h"

t_node	*new_cursor_node(char *s, char end, int flags)
{
	t_node	*ret;

	ret = (t_node *)malloc(sizeof(t_node));
	ret->prev = NULL;
	ret->start = s;
	ret->ptr = s;
	ret->end = end;
	ret->flag = flags;
	return (ret);
}

void	init_cursor(t_cursor *cursor, char *s)
{
	cursor->cur = new_cursor_node(s, '\0', CURSOR_SPECIAL);
}

void	destruct_cursor(t_cursor *cursor)
{
	t_node	*cur;
	t_node	*tmp;

	cur = cursor->cur;
	while (cur)
	{
		tmp = cur;
		cur = cur->prev;
		if (tmp->flag & CURSOR_OWNERSHIP)
			free(tmp->start);
		free(tmp);
	}
}

void	push_cursor(t_cursor *cursor, char *s, int flags)
{
	t_node	*node;

	node = new_cursor_node(s, '\0', flags);
	node->prev = cursor->cur;
	cursor->cur = node;
}
