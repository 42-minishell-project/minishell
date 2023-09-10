/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:52:48 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 13:18:45 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include "env/env.h"
#include "command/execute.h"

void	set_sigint(void)
{
	if (g_child_pid == 0)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		update_last_exit_code(1);
	}
	else
	{
		kill(g_child_pid, SIGINT);
	}
}

void	set_sigquit(void)
{
	if (g_child_pid != 0)
	{
		ft_putstr_fd("Quit: 3\n", 1);
		// update_last_exit_code(1);
	}
}

void	print_prompt_cursor(void)
{
	// ft_putstr_fd("\033[1A\033[1Cexit", STDOUT_FILENO);
	// ft_putstr_fd("\033[1A\033[1C\nexit\n", STDOUT_FILENO);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	// ft_putstr_fd("", STDOUT_FILENO);
	// ft_putstr_fd(" \n", STDOUT_FILENO);
}

void	set_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
