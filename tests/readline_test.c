

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

int main() {
	char *l1 = readline("> ");
	char *l2 = readline("> ");
	char *l12 = malloc(2 + strlen(l1) + strlen(l2));
	strcpy(l12, l1);
	strcat(l12, "\n");
	strcat(l12, l2);
	printf("line %s\n", l12);
	add_history(l12);
	char *l3 = readline("> ");
	printf("line %s\n", l3);
	add_history(l3);
	char *l4 = readline("> ");
	printf("line %s\n", l4);
	add_history(l3);
	char *l5 = readline("> ");
	printf("line %s\n", l5);
}
