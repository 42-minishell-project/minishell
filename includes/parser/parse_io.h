/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:52:28 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 19:07:33 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_IO_H
# define PARSE_IO_H

# include "parser/io_file.h"
# include "parser/typedefs.h"

int			open_heredoc(const char *eof, int *exit_code);
t_io_file	make_io_file(t_special_type type, char *s);
t_io_file	make_heredoc_from_token(t_token *token, int *exit_code);

#endif
