/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:57:53 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 17:19:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils/cmd_array.h"

int	parse_line(char *line, t_cmd_arr *cmds);
int	check_command_nonempty(char *line);

#endif
