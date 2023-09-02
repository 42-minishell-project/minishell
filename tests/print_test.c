#include <stdio.h>
#include <limits.h>
#include <unistd.h>	// chdir header

void print_chdir(void)
{
	char changeDir[PATH_MAX] = { "/Users/hong-yeonghwan/Desktop" };

	int result = chdir(changeDir);

	if(result == 0)
		printf("Success\n");
	else
		perror("Fail...\n");
}

void print_env(char **envp)
{
	int i = 0;
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
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