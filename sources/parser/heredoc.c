/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:05:17 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 18:40:03 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include "libft/libft.h"
#include "command/exec_utils.h"
#include "utils/error.h"
#include "signal/signal.h"

void	get_heredoc_content(const char *eof, int write_fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, eof) == 0)
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
	close(write_fd);
}

int	open_heredoc(const char *eof, int *exit_code)
{
	int	pipe_fd[2];
	int	pid;
	int	status;

	if (pipe(pipe_fd) == -1)
		fatal_error("pipe() failed");
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		printf("%d: get input - heredoc\n", getpid());
		close(pipe_fd[0]);
		get_heredoc_content(eof, pipe_fd[1]);
		exit(0);
	}
	printf("heredoc: child %d\n", pid);
	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	*exit_code = status_to_exit_code(status);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	printf("heredoc: child exit %d\n", *exit_code);
	if (*exit_code != 0)
	{
		close(pipe_fd[0]);
		pipe_fd[0] = -1;
	}
	return (pipe_fd[0]);
}

