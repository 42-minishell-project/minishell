/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:48:33 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 18:55:16 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser/parse_io.h"
#include "parser/parse_error.h"
#include "utils/io_array.h"

t_io_file	make_io_file(t_special_type type, char *s)
{
	t_io_file	ret;

	ret.fd = -1;
	ret.str = s;
	if (type == SP_IN)
	{
		ret.type = IO_IN_FILE;
	}
	else if (type == SP_OUT)
	{
		ret.type = IO_OUT_TRUNC;
	}
	else if (type == SP_OUT_APPEND)
	{
		ret.type = IO_OUT_APPEND;
	}
	else
		ret.type = IO_NONE;
	return (ret);
}

t_io_file	make_heredoc_from_token(t_token *token, int *exit_code)
{
	t_io_file	ret;

	ret.fd = open_heredoc(token->s, exit_code);
	ret.str = NULL;
	ret.type = IO_IN_HEREDOC;
	free(token->s);
	token->s = NULL;
	return (ret);
}
