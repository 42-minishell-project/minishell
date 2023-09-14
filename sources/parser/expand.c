/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:38:50 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:51:13 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parser/cursor.h"
#include "command/execute.h"
#include "env/env.h"
#include "utils/chr_array.h"

void	expand_env_name(t_cursor *s)
{
	char		c;
	t_chr_arr	*name;
	char		*env_value;

	name = new_chr_array();
	c = peek_cursor(s);
	if (c == '_' || ft_isalpha(c))
	{
		while (1)
		{
			c = peek_cursor(s);
			if (!c || !(c == '_' || ft_isalnum(c)))
				break ;
			push_chr_array(name, forward_cursor(s));
		}
	}
	if (name->size == 0)
		push_cursor(s, "$", CURSOR_NOEXPAND);
	else
	{
		env_value = find_env(name->arr);
		if (env_value)
			push_cursor(s, env_value, CURSOR_NOEXPAND);
	}
	delete_chr_array(name);
}

void	expand_env(t_cursor *s)
{
	char	c;

	forward_cursor(s);
	c = peek_cursor(s);
	if (c == '?')
	{
		forward_cursor(s);
		push_cursor(s, ft_itoa(g_last_exit_code), CURSOR_OWNERSHIP);
	}
	else
		expand_env_name(s);
}

char	peek_cursor_with_env(t_cursor *s)
{
	char	c;

	c = peek_cursor(s);
	if (c == '$' && !(s->cur->flag & CURSOR_NOEXPAND))
	{
		expand_env(s);
		c = peek_cursor_with_env(s);
	}
	return (c);
}
