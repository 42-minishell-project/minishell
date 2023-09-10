/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:53:49 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 16:04:28 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft/libft.h"
#include "command/open_io.h"
#include "utils/io_array.h"
#include "utils/error.h"

int	open_in_file_noerror(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int	open_out_file_noerror(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

int	open_out_file_append_noerror(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	print_open_error_noexcept(char *filename)
{
	perror(filename);
	return (-1);
}

int	prepare_io_noexcept(t_io_arr *io)
{
	int			idx;
	t_io_type	type;
	int			fd;

	idx = 0;
	while (idx < io->size)
	{
		type = io->arr[idx].type;
		if (type == IO_IN_FILE || type == IO_IN_HEREDOC)
		{
			if (type == IO_IN_FILE)
				fd = open_in_file(io->arr[idx].str);
			else
				fd = io->arr[idx].fd;
			if (fd < 0)
				return (print_open_error_noexcept(io->arr[idx].str));
			if (dup2(fd, STDIN_FILENO) == -1)
				fatal_error("dup2() failed");
			close(fd);
		}
		if (type == IO_OUT_TRUNC || type == IO_OUT_APPEND)
		{
			if (type == IO_OUT_TRUNC)
				fd = open_out_file(io->arr[idx].str);
			else
				fd = open_out_file_append(io->arr[idx].str);
			if (fd < 0)
				return (print_open_error_noexcept(io->arr[idx].str));
			if (dup2(fd, STDOUT_FILENO) == -1)
				fatal_error("dup2() failed");
			close(fd);
		}
		idx++;
	}
	return (0);
}
