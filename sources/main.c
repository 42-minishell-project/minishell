/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 03:13:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 15:21:47 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
// #include "env.h"
// #include "env_utils.h"
// #include "env/env_test.h"
#include "env/env.h"
#include "parser/parser.h"
#include "command/env_path.h"
#include "command/execute.h"
#include "builtin/builtin.h"

#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>

void sig_handler(int signal)
{
    if (signal == SIGINT)
    {
        printf(">\n");
    }
    if (rl_on_new_line() == -1) // readline으로 설정한 문자열을 한 번 출력한다?
        exit(1);
    rl_replace_line("", 1); // 프롬프트에 이미 친 문자열을 싹 날려준다.
    rl_redisplay();         // 프롬프트 커서가 움직이지 않게 해준다.
}

 void print_parsing(t_cmd_arr *arr)
 {
 	printf("t_cmd_arr\n");
 	printf("size : %d capa : %d\n",arr->size , arr->capa);

 	printf("t_command\n");
 	printf("1. t_str_arr\n");
 	printf("size : %d capa : %d\n",arr->arr->token->size , arr->arr->token->capa);
 	printf("arr[][] = \n");
 	for(int i = 0 ; i < arr->arr->token->size ; i++) {
 		printf("%d : %s\n", i + 1 , arr->arr->token->arr[i]);
 	}
 	printf("2. t_io_arr\n");
 	printf("size : %d capa : %d\n",arr->arr->io->size , arr->arr->io->capa);
 	for(int i = 0 ; i < arr->arr->io->size ; i++) {
 		printf("fd : %d : %s\n",arr->arr->io->arr->fd , arr->arr->io->arr->str);
 	}
 }

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
	// init_envp(envp);
	
	
	//struct termios term;
    // tcgetattr(STDIN_FILENO, &term);
    // term.c_lflag &= ~(ECHOCTL);
    // tcsetattr(STDIN_FILENO, TCSANOW, &term);
	
	signal(SIGINT, sig_handler); // CTRL + C
    signal(SIGQUIT, SIG_IGN);    // CTRL + /

	init_envs(envp);
	init_paths(envp);
	char *line;
	t_cmd_arr *arr;

	
	
	while(1)
	{
		line = readline("> ");
		
		add_history(line);
		if (!line)
        {
			printf("\033[1A");
            printf("\033[1C");
            printf(" exit\n");
            exit(0);
        }
		arr = parse_line(line);
		
		//print_parsing(arr);
		
		printf("=========start\n");
		//int a = init_builtin(argc, arr->arr->token->arr);
		t_command *b = arr->arr;
		int a = init_builtin(b);
		printf("exit_code : %d\n", a);
		// execute_commands(arr);
		printf("=========done\n");
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

	