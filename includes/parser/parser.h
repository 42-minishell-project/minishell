/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:57:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 16:01:56 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils/cmd_array.h"

t_cmd_arr	*parse_line(char *line);
int			check_command_nonempty(char *line);

#endif
