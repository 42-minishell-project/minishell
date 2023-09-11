/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:31:51 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 16:01:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/cursor.h"

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
