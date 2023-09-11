/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:52:48 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/11 18:42:45 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include "libft/libft.h"
#include "env/env.h"
#include "command/execute.h"

void	set_sigint(void)
{
	update_last_exit_code(1);
	if (g_child_pid != 0)
		ft_putstr_fd("^C\n", STDOUT_FILENO);
	else
		ft_putstr_fd("\n", STDOUT_FILENO);
}

void	set_sigquit(void)
{
	if (g_child_pid != 0)
	{
		ft_putstr_fd("Quit: 3\n", 1);
	}
}

void	print_prompt_cursor(void)
{
	ft_putstr_fd("\033[1Aminishell$ exit\n", STDOUT_FILENO);
}

void	print_signal_d(void)
{
	print_prompt_cursor();
	exit(0);
}

void	set_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
