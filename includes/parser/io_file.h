/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 03:50:14 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:54:21 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_FILE_H
# define IO_FILE_H

typedef enum e_io_type
{
	IO_NONE = 0,
	IO_IN_FILE = 1,
	IO_IN_HEREDOC = 2,
	IO_OUT_TRUNC = 3,
	IO_OUT_APPEND = 4
}	t_io_type;

typedef struct s_io_file
{
	int			fd;
	char		*str;
	t_io_type	type;
}	t_io_file;

#endif
