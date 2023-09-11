/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:08:32 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 19:36:23 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include "parser/typedefs.h"
# include "parser/cursor.h"

int				is_special(t_cursor *s, char c);
t_special_type	check_special_type(t_cursor *s);
char			*io_token_type_to_str(t_special_type type);
void			trim_whitespace(t_cursor *s, int expand_env);

#endif
