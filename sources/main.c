/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 11:43:25 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "env/env.h"
#include "parser/parser.h"
#include "command/env_path.h"
#include "command/execute.h"
#include "builtin/builtin.h"
#include "utils/signal_utils.h"
#include <string.h>
#include "libft/libft.h"

int	g_child_pid;

void	sig_handler(int signal)
{
	if (signal == SIGINT)
		set_sigint();
	else if (signal == SIGQUIT)
		set_sigquit();
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

void	set_handler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}

int	main(int argc, char *argv[], char *envp[])
{
	char			*line;
	t_cmd_arr		*arr;

	set_term();
	set_handler();

	init_envs(envp);
	// while (1)
	for (int i = 0; i < 10; i++)
	{
		line = readline("> ");
		if (!line)
		{
			print_prompt_cursor();
			exit(0);
		}
		if (check_command_nonempty(line))
		{
			add_history(line);
			arr = parse_line(line);
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

	