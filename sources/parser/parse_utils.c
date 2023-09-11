/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:05:28 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 19:20:39 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parser/parse_utils.h"

int	is_special(t_cursor *s, char c)
{
	if (s->cur->flag & CURSOR_SPECIAL)
	{
		if (c == '<' || c == '>' || c == '|')
			return (1);
	}
	return (0);
}

t_special_type	check_special_type_double(t_cursor *s, char c)
{
	if (c == '>')
	{
		if (peek_cursor(s) == '>')
		{
			forward_cursor(s);
			return (SP_OUT_APPEND);
		}
		return (SP_OUT);
	}
	else if (c == '<')
	{
		if (peek_cursor(s) == '<')
		{
			forward_cursor(s);
			return (SP_IN_HEREDOC);
		}
		return (SP_IN);
	}
	return (SP_NONE);
}

t_special_type	check_special_type(t_cursor *s)
{
	char	c;

	if (s->cur->flag & CURSOR_SPECIAL)
	{
		c = peek_cursor(s);
		if (c == '>' || c == '<' || c == '|')
			forward_cursor(s);
		if (c == '>' || c == '<')
			return (check_special_type_double(s, c));
		else if (c == '|')
			return (SP_PIPE);
	}
	return (SP_NONE);
}

char	*io_token_type_to_str(t_special_type type)
{
	if (type == SP_IN)
		return ("<");
	if (type == SP_IN_HEREDOC)
		return ("<<");
	if (type == SP_OUT)
		return (">");
	if (type == SP_OUT_APPEND)
		return (">>");
	if (type == SP_PIPE)
		return ("|");
	return ("newline");
}

void	trim_whitespace(t_cursor *s, int expand_env)
{
	char	c;

	while (1)
	{
		if (expand_env)
			c = peek_cursor_with_env(s);
		else
			c = peek_cursor(s);
		if (!c || !ft_isspace(c))
			break ;
		else
			forward_cursor(s);
	}
}
