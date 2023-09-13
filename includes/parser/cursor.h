/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:32:02 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:22:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

typedef struct s_node
{
	struct s_node	*prev;
	char			*start;
	char			*ptr;
	char			end;
	int				flag;
}	t_node;

typedef struct s_cursor
{
	t_node	*cur;
}	t_cursor;

typedef enum e_cursor_flag
{
	CURSOR_OWNERSHIP = 1 << 0,
	CURSOR_SPECIAL = 1 << 1,
	CURSOR_NOEXPAND = 1 << 2
}	t_cursor_flag;

void	init_cursor(t_cursor *cursor, char *s);
void	destruct_cursor(t_cursor *cursor);
char	peek_cursor(t_cursor *cursor);
char	forward_cursor(t_cursor *cursor);
void	push_cursor(t_cursor *cursor, char *s, int flags);
char	peek_cursor_with_env(t_cursor *s);

#endif
