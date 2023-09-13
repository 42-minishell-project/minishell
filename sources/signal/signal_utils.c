/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:52:48 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/13 20:31:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include "libft/libft.h"
#include "env/env.h"
#include "command/execute.h"

void	exit_eof(void)
{
	ft_putstr_fd("\033[1Aminishell$ exit\n", STDOUT_FILENO);
	exit(0);
}

void	set_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
