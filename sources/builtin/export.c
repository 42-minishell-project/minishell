/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:35:46 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 17:28:22 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env.h"
#include "utils/utils.h"
#include "utils/builtin_error.h"

//#include <stdio.h>

//static int	print_export(char **argv)
//{
//	int i = 0;
//	while (argv[i])
//		printf("%s\n",argv[i]);
//}

int	run_export(int argc, char **argv)
{
	int		idx;
	int		valid;
	char	*name;
	char	*value;

	valid = 0;
	idx = 1;
	//if (argc == 1)
	//	print_export(argv);
	while (idx < argc)
	{
		if (parse_identifier(argv[idx], &name, &value))
		{
			if (name && value)
				update_env(name, value);
			free(name);
			free(value);
		}
		else
		{
			print_builtin_error("export", argv[idx], \
				": not a valid identifier", 1);
			valid = 1;
		}
		idx++;
	}
	return (valid);
}
