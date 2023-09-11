/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:52:52 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:15:30 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_IO_H
# define OPEN_IO_H

int	open_in_heredoc(char *eof);
int	open_in_file(char *file);
int	open_out_file(char *file);
int	open_out_file_append(char *file);

#endif
