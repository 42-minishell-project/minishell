/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:15:30 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:26:24 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "command/open_io.h"
#include "command/redirect.h"
#include "utils/error.h"

int	open_io_type(t_io_file *file, int *redirect_to)
{
	int			fd;
	t_io_type	type;

	fd = -1;
	type = file->type;
	if (type == IO_IN_FILE || type == IO_IN_HEREDOC)
	{
		if (type == IO_IN_FILE)
			fd = open_in_file(file->str);
		else
			fd = file->fd;
		*redirect_to = STDIN_FILENO;
	}
	else if (type == IO_OUT_TRUNC || type == IO_OUT_APPEND)
	{
		if (type == IO_OUT_TRUNC)
			fd = open_out_file(file->str);
		else
			fd = open_out_file_append(file->str);
		*redirect_to = STDOUT_FILENO;
	}
	return (fd);
}

void	prepare_io(t_io_arr *io)
{
	int	idx;
	int	fd;
	int	redirect_to;

	idx = 0;
	while (idx < io->size)
	{
		fd = open_io_type(&io->arr[idx], &redirect_to);
		if (fd < 0)
			fatal_error(io->arr[idx].str);
		if (dup2(fd, STDIN_FILENO) == -1)
			fatal_error("dup2() failed");
		close(fd);
		idx++;
	}
}

int	prepare_io_noexcept(t_io_arr *io)
{
	int	idx;
	int	fd;
	int	redirect_to;

	idx = 0;
	while (idx < io->size)
	{
		fd = open_io_type(&io->arr[idx], &redirect_to);
		if (fd < 0)
		{
			perror(io->arr[idx].str);
			return (-1);
		}
		if (dup2(fd, STDIN_FILENO) == -1)
			fatal_error("dup2() failed");
		close(fd);
		idx++;
	}
	return (0);
}
