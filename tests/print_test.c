#include <stdio.h>
#include <limits.h>
#include <unistd.h>	// chdir header
#include <stdlib.h>
#include <sys/stat.h>
int main(void)
{

	char *path = "abc/a";

    struct stat fileStat;
    
    // stat 함수를 사용하여 파일/폴더에 대한 정보를 가져옵니다.
    if (stat(path, &fileStat) == -1) {
        perror("cd");
        return 1; // 오류 발생
    }

    if (S_ISDIR(fileStat.st_mode)) {
        printf("%s 는 폴더입니다.\n", path);
    } else if (S_ISREG(fileStat.st_mode)) {
        printf("%s 는 일반 파일입니다.\n", path);
    } else {
        printf("%s 는 폴더도 일반 파일도 아닙니다.\n", path);
    }

    return 0; // 성공
}

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

// void print_parsing(t_cmd_arr *arr)
// {
// 		printf("t_cmd_arr\n");
// 	printf("size : %d capa : %d\n",arr->size , arr->capa);

// 	printf("t_command\n");
// 	printf("1. t_str_arr\n");
// 	printf("size : %d capa : %d\n",arr->arr->token->size , arr->arr->token->capa);
// 	printf("arr[][] = \n");
// 	for(int i = 0 ; i < arr->arr->token->size ; i++) {
// 		printf("%d : %s\n", i + 1 , arr->arr->token->arr[i]);
// 	}
// 	printf("2. t_io_arr\n");
// 	printf("size : %d capa : %d\n",arr->arr->io->size , arr->arr->io->capa);
// 	for(int i = 0 ; i < arr->arr->io->size ; i++) {
// 		printf("fd : %d : %s\n",arr->arr->io->arr->fd , arr->arr->io->arr->str);
// 	}


// }