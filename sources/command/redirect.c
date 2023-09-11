/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:15:30 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 18:27:11 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "command/open_io.h"
#include "command/redirect.h"
#include "utils/error.h"
#include "libft/libft.h"

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
		if (dup2(fd, redirect_to) == -1)
			fatal_error("dup2() failed");
		close(fd);
		idx++;
	}
}

void	fatal_error_noexcept(const char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (ft_strlen(message) == 0)
		ft_putstr_fd(": ", STDERR_FILENO);
	perror(message);
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
			fatal_error_noexcept(io->arr[idx].str);
			return (-1);
		}
		if (dup2(fd, redirect_to) == -1)
		{
			close(fd);
			return (-1);
		}
		close(fd);
		idx++;
	}
	return (0);
}
