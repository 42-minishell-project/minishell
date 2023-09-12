/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:05:39 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 09:50:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "builtin/builtin_utils.h"
#include "env/env.h"

int	run_unset(int argc, char **argv)
{
	int		idx;
	int		exit_code;

	exit_code = 0;
	idx = 1;
	while (idx < argc)
	{
		if (parse_identifier(argv[idx], NULL, NULL) == 1)
		{
			delete_env(argv[idx]);
		}
		else
		{
			print_identifier_error("unset", argv[idx]);
			exit_code = 1;
		}
		idx++;
	}
	return (exit_code);
}
