/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 19:31:34 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

int	g_child_pid;

int	main(int argc, char *argv[], char *envp[])
{
	char		*line;
	t_cmd_arr	*arr;
	int			ret;

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
			arr = new_cmd_array();
			ret = parse_line(line, arr);
			signal(SIGQUIT, sig_handler);
			if (ret == 0)
				ret = execute_commands(arr);
			signal(SIGQUIT, SIG_IGN);
			update_last_exit_code(ret);
			delete_cmd_array(arr);
		}
		free(line);
	}
}
