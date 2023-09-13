/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:12:39 by jimlee           ###   ########.fr       */
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
#include "command/execute.h"
#include "builtin/builtin.h"
#include "utils/cmd_array.h"
#include <string.h>
#include "libft/libft.h"
#include "signal/signal.h"
#include "signal/signal_utils.h"

int	g_last_exit_code;

int	main(int argc, char *argv[], char *envp[])
{
	char		*line;
	t_cmd_arr	*arr;
	int			ret;

	(void)argc;
	(void)argv;
	set_term();
	// set_handler();
	init_envs(envp);
	signal(SIGINT, sigint_enter_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			print_signal_d();
		if (check_command_nonempty(line))
		{
			add_history(line);
			arr = new_cmd_array();
			ret = parse_line(line, arr);
			// signal(SIGQUIT, sig_handler);
			if (ret == 0)
			{
				signal(SIGINT, sigint_run_handler);
				signal(SIGQUIT, sigquit_handler);
				ret = execute_commands(arr);
				signal(SIGINT, sigint_enter_handler);
				signal(SIGQUIT, SIG_IGN);
			}
			// signal(SIGQUIT, SIG_IGN);
			g_last_exit_code = ret;
			delete_cmd_array(arr);
		}
		free(line);
	}
}
