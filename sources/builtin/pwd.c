/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:33:54 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 16:02:14 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin/builtin.h"
#include "libft/libft.h"

int	run_pwd(int argc, char **argv)
{
	char	*path;

	(void) argc;
	(void) argv;
	path = getcwd(NULL, 0);
	if (!path)
		return (1);
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	free(path);
	path = NULL;
	return (0);
}
