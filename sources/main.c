/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/02 17:00:38 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "env/env.h"
#include "env/env_utils.h"
#include "env/env_test.h"
#include "parser/parser.h"
#include "command/env_path.h"
#include "command/execute.h"

#include "builtin/builtin.h"

int	main(int argc, char *argv[], char *envp[])
{
	// init_envs(envp);

	// t_env *cur = get_env_list_head()->next;
	// int idx = 0;
	// while (!cur->next) {
	// 	printf("%02d name: %s, value: \"%s\"\n", idx, cur->name, cur->value);
	// 	cur = cur->next;
	// 	idx++;
	// }
	
	// printf("\n\n");

	init_envs(envp);
	printf("HOME : %s\n",find_env_by_name("HOME"));
	printf("PWD : %s\n",find_env_by_name("PWD"));
	printf("OLDPWD : %s\n",find_env_by_name("OLDPWD"));
	
	init_envp(envp);
	init_paths(envp);
	char *line;
	t_cmd_arr *arr;

	while(1)
	{
		line = readline("> ");
		printf("%s\n", line);
		arr = parse_line(line);

		printf("\nstart execute\n=========\n");
		init_builtin(arr->arr->token->arr);
		// execute_commands(arr);
		printf("=========\ndone\n");
	}
	


	delete_cmd_array(arr);
	delete_paths();
	free(line);
}


	// for (int i = 0; i < arr->size; i++)
	// {
	// 	t_command cmd = arr->arr[i];
	// 	printf("CMD %d:\n", i);
	// 	printf("    %d TOKENS:\n", cmd.token->size);
	// 	for (int j = 0; j < cmd.token->size; j++)
	// 	{
	// 		printf("        \"%s\"\n", cmd.token->arr[j]);
	// 	}
	// 	printf("    %d IO:\n", cmd.io->size);
	// 	for (int j = 0; j < cmd.io->size; j++)
	// 	{
	// 		char *name;
	// 		if (cmd.io->arr[j].type == IO_IN_FILE)
	// 			name = "infile";
	// 		else if (cmd.io->arr[j].type == IO_IN_HEREDOC)
	// 			name = "infile_heredoc";
	// 		else if (cmd.io->arr[j].type == IO_OUT_TRUNC)
	// 			name = "outfile";
	// 		else if (cmd.io->arr[j].type == IO_OUT_APPEND)
	// 			name = "outfile_append";
	// 		printf("        %s: \"%s\"\n", name, cmd.io->arr[j].str);
	// 	}
	// }

	