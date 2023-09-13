/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:34:13 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "env/env.h"
#include "parser/parser.h"
#include "command/execute.h"
#include "signal/signal.h"
#include "signal/signal_utils.h"

int	g_last_exit_code;

void	initialize(char **envp)
{
	set_term();
	init_envs(envp);
	signal(SIGINT, sigint_enter_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	parse_and_run(char *line)
{
	t_cmd_arr	*arr;
	int			ret;

	add_history(line);
	arr = new_cmd_array();
	ret = parse_line(line, arr);
	if (ret == 0)
	{
		signal(SIGINT, sigint_run_handler);
		signal(SIGQUIT, sigquit_handler);
		ret = execute_commands(arr);
		signal(SIGINT, sigint_enter_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	g_last_exit_code = ret;
	delete_cmd_array(arr);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	(void)argc;
	(void)argv;
	initialize(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			exit_eof();
		}
		if (check_command_nonempty(line))
		{
			parse_and_run(line);
		}
		free(line);
	}
}
