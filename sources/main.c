/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/08 12:41:00 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
// #include "env.h"
// #include "env_utils.h"
// #include "env/env_test.h"
#include "env/env.h"
#include "parser/parser.h"
#include "command/env_path.h"
#include "command/execute.h"
#include "builtin/builtin.h"

#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include "libft/libft.h"

int	g_child_pid;

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		if (g_child_pid == 0)
		{
			printf(">\n");
			// g_child_pid = 1;
		}
		else
		{
			kill(g_child_pid, SIGINT);
			g_child_pid = 130;
		}
	}
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

int	main(int argc, char *argv[], char *envp[])
{
	struct termios	term;
	char			*line;
	t_cmd_arr		*arr;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);

	init_envs(envp);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("\033[1A",1);
			ft_putstr_fd("\033[1C",1);
			ft_putstr_fd(" exit\n",1);
			exit(0);
		}
		add_history(line);
		arr = parse_line(line);
		free(line);
		if (!arr)
			continue;
		printf("=========start\n");
		int ret = execute_commands(arr);
		update_last_exit_code(ret);
		delete_cmd_array(arr);
		printf("=========done\n");
	}
	free(line);
}


	// for (int i = 0; i < arr->size; i++)
	// {
	// 	t_command cmd = arr->arr[i];
	// 	printf("CMD %d:\n", i);
	// 	printf("    %d TOKENS:\n", cmd.token->size);
	// 	for (int j = 0; j < cmd.token->size; j++)
	// 	{
	// 		printf("        \"%s\"\n", cmd.token->arr[j]);
	// 	}
	// 	printf("    %d IO:\n", cmd.io->size);
	// 	for (int j = 0; j < cmd.io->size; j++)
	// 	{
	// 		char *name;
	// 		if (cmd.io->arr[j].type == IO_IN_FILE)
	// 			name = "infile";
	// 		else if (cmd.io->arr[j].type == IO_IN_HEREDOC)
	// 			name = "infile_heredoc";
	// 		else if (cmd.io->arr[j].type == IO_OUT_TRUNC)
	// 			name = "outfile";
	// 		else if (cmd.io->arr[j].type == IO_OUT_APPEND)
	// 			name = "outfile_append";
	// 		printf("        %s: \"%s\"\n", name, cmd.io->arr[j].str);
	// 	}
	// }

	