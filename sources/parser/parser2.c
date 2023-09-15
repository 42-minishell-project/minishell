/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:55:09 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/15 22:18:59 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "parser/parse_func.h"
#include "parser/parse_io.h"
#include "parser/parse_utils.h"
#include "parser/parse_error.h"
#include "utils/chr_array.h"

int	parse_io_file(t_cursor *s, t_special_type type, t_io_arr *io)
{
	t_parse_result	ret;
	t_token			tmp;
	t_io_file		file;
	int				heredoc_exit_code;

	tmp.s = NULL;
	tmp.type = SP_NONE;
	ret = parse_next_token(&tmp, s);
	if (ret == RES_ERROR)
		return (2);
	else if (ret == RES_END || tmp.type != SP_NONE)
	{
		syntax_error_unexpected_token(io_token_type_to_str(tmp.type));
		return (2);
	}
	if (type == SP_IN_HEREDOC)
	{
		file = make_heredoc_from_token(&tmp, &heredoc_exit_code);
		if (heredoc_exit_code != 0)
			return (heredoc_exit_code);
	}
	else
		file = make_io_file(type, tmp.s);
	push_io_array(io, file);
	return (0);
}

int	parse_single_quote(t_cursor *s, t_chr_arr *token)
{
	char	c;

	forward_cursor(s);
	while (1)
	{
		c = peek_cursor(s);
		if (c == '\'')
			break ;
		if (!c)
			return (unexpected_eof_matching_error('\''));
		else
			push_chr_array(token, forward_cursor(s));
	}
	forward_cursor(s);
	return (0);
}

int	parse_double_quote(t_cursor *s, t_chr_arr *token)
{
	char	c;

	forward_cursor(s);
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (c == '\"')
			break ;
		else if (!c)
			return (unexpected_eof_matching_error('\"'));
		else
			push_chr_array(token, forward_cursor(s));
	}
	forward_cursor(s);
	return (0);
}

t_parse_result	parse_next_token_internal(t_chr_arr *token, t_cursor *s)
{
	char			c;
	t_parse_result	ended;

	ended = RES_END;
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (!c || ft_isspace(c) || is_special(s, c))
			break ;
		ended = RES_OK;
		if (c == '\'')
		{
			if (parse_single_quote(s, token) == -1)
				return (RES_ERROR);
		}
		else if (c == '\"')
		{
			if (parse_double_quote(s, token) == -1)
				return (RES_ERROR);
		}
		else
			push_chr_array(token, forward_cursor(s));
	}
	return (ended);
}

t_parse_result	parse_next_token(t_token *ret, t_cursor *s)
{
	t_chr_arr		*token;
	t_parse_result	result;

	ret->type = SP_NONE;
	ret->s = NULL;
	trim_whitespace(s, 1);
	if (!peek_cursor(s))
		return (RES_END);
	if (is_special(s, peek_cursor(s)))
	{
		ret->type = check_special_type(s);
		return (RES_OK);
	}
	token = new_chr_array();
	result = parse_next_token_internal(token, s);
	if (result == RES_OK)
		ret->s = copy_chr_arr_to_string(token);
	delete_chr_array(token);
	return (result);
}
