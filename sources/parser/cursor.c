/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:31:51 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/23 13:32:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/cursor.h"

#include <stdio.h>
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
	// printf("init cursor %s\n", s);
	cursor->cur = new_cursor_node(s, '\0', CURSOR_SPECIAL);
	// printf("cursor->cur->ptr %s\n", cursor->cur->ptr);
}

void	delete_cursor(t_cursor *cursor)
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

#include <stdio.h>
char	peek_cursor(t_cursor *cursor)
{
	if (!cursor->cur)
		return ('\0');
	// printf("peek - ptr %p, c \'%c\'\n", cursor->cur->ptr, 
	// 	(cursor->cur->ptr ? (*cursor->cur->ptr) : '.'));
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

void	push_cursor(t_cursor *cursor, char *s, int flags)
{
	t_node	*node;

	node = new_cursor_node(s, '\0', flags);
	node->prev = cursor->cur;
	cursor->cur = node;
}
