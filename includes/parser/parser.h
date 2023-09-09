/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:57:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/09 21:02:38 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils/cmd_array.h"


// t_chr_arr	*parse_next_token(t_cursor *s);
// t_str_arr	*split_by_pipes(char *s);

t_cmd_arr	*parse_line(char *line);
int			check_command_nonempty(char *line);

#endif
