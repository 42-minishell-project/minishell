#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("prompt : ");
		printf("\"%s\"\n", str);
		if (!str)
			break ;
		rl_on_new_line();
		rl_replace_line("replace line\n", 1);
		rl_redisplay();
		printf("\n");
		add_history(str);
		free(str);
	}
	return (0);
}
