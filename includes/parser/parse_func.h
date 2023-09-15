/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:03:14 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/15 22:17:30 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FUNC_H
# define PARSE_FUNC_H

# include "parser/cursor.h"
# include "parser/typedefs.h"
# include "utils/io_array.h"

int				parse_io_file(t_cursor *s, t_special_type type, t_io_arr *io);
t_parse_result	parse_next_token(t_token *ret, t_cursor *s);

#endif
