/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:52:52 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 12:06:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_IO_H
# define OPEN_IO_H

int	open_in_heredoc(char *eof);
int	open_in_file(char *file);
int	open_out_file(char *file);
int	open_out_file_append(char *file);

#endif
