/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:46:50 by yeohong          ###   ########.fr       */
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
	if (!(signal == SIGINT && g_child_pid != 0))
	{
		if (rl_on_new_line() == -1)
			exit(1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
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
	int				ret;

	set_term();
	set_handler();
	init_envs(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			print_signal_d();
		if (check_command_nonempty(line))
		{
			add_history(line);
			arr = parse_line(line);
			if (!arr)
				continue ;
			ret = execute_commands(arr);
			update_last_exit_code(ret);
			delete_cmd_array(arr);
		}
		free(line);
	}
}
