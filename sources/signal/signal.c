/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:32:09 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/11 19:32:16 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "command/execute.h"
#include "signal/signal_utils.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		set_sigint();
		if (g_child_pid == 0)
		{
			if (rl_on_new_line() == -1)
				exit(1);
			rl_replace_line("", 1);
			rl_redisplay();
		}
	}
	else if (signal == SIGQUIT)
	{
		set_sigquit();
	}
}

void	set_handler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
