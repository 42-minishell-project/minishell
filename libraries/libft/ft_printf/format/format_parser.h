/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:08 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 21:52:15 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PARSER_H
# define FORMAT_PARSER_H

# include "format.h"
# include "libft.h"

int	parse_format_string(const char *s, t_format *format);

#endif
