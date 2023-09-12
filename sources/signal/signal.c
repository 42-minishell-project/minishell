/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:32:09 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/12 17:14:47 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "command/execute.h"
#include "signal/signal_utils.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "env/env.h"

// 실행상태 일 때 ctrl - c 
void	sigint_run_handler(int signal)
{
	update_last_exit_code(1);
	if (g_child_pid != 0)
		ft_putstr_fd("^C\n", STDOUT_FILENO);
}

// 입력상태 일 때 ctrl - c 
void	sigint_enter_handler(int signal)
{
	update_last_exit_code(1);
	if (g_child_pid == 0)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		if (rl_on_new_line() == -1)
			exit(1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	sigquit_handler(void)
{
	if (g_child_pid != 0)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	}
}

// void	sig_handler(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		set_sigint();
// 		if (g_child_pid == 0)
// 		{
// 			if (rl_on_new_line() == -1)
// 				exit(1);
// 			rl_replace_line("", 1);
// 			rl_redisplay();
// 		}
// 	}
// 	else if (signal == SIGQUIT)
// 	{
// 		set_sigquit();
// 	}
// }

// void	set_handler(void)
// {
// 	signal(SIGINT, sig_handler);
// 	signal(SIGQUIT, SIG_IGN);
// }
