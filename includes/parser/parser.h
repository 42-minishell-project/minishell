/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:57:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 18:35:46 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils/cmd_array.h"

typedef enum e_special_type
{
	SP_NONE = 0,
	SP_IN = 1,
	SP_IN_HEREDOC = 2,
	SP_OUT = 3,
	SP_OUT_APPEND = 4,
	SP_PIPE = 5
}	t_special_type;


typedef struct s_token
{
	char			*s;
	t_special_type	type;
}	t_token;

typedef enum e_parse_result
{
	RES_START = 0,
	RES_END = 1,
	RES_PIPE = 2,
	RES_ERROR = 3
}	t_parse_result;

// t_chr_arr	*parse_next_token(t_cursor *s);
// t_str_arr	*split_by_pipes(char *s);

t_cmd_arr	*parse_line(char *line);

#endif
