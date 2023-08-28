

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "parser/cursor.h"
// #include "env.h"
#include "command/command.h"

#include "utils/chr_array.h"
#include "utils/str_array.h"
#include "utils/io_array.h"
#include "utils/cmd_array.h"
#include "parser/cursor.h"


void	expand_env(t_cursor *s)
{
	char		c;
	t_chr_arr	*name;
	char		*env_value;

	forward_cursor(s);
	name = new_chr_array();
	while (1)
	{
		c = peek_cursor(s);
		if (!c || !(c == '_' || ft_isalnum(c)))
			break ;
		push_chr_array(name, forward_cursor(s));
	}
	if (name->size == 0)
		push_cursor(s, "$", 0);
	else
	{
		// printf("env name %s\n", name->arr);
		// env_value = find_env_by_name(name->arr);
		env_value = getenv(name->arr);
		// printf("find env %s = \"%s\"\n", name->arr, env_value);
		if (env_value)
			push_cursor(s, env_value, 0);
	}
	delete_chr_array(name);
}

char	peek_cursor_with_env(t_cursor *s)
{
	char	c;

	c = peek_cursor(s);
	if (c == '$')
	{
		expand_env(s);
		c = peek_cursor(s);
	}
	return (c);
}

int	is_special(t_cursor *s, char c)
{
	if (s->cur->flag & CURSOR_SPECIAL)
	{
		if (c == '<' || c == '>' || c == '|')
			return (1);
	}
	return (0);
}

t_special_type	check_special_type(t_cursor *s)
{
	char	c;

	if (s->cur->flag & CURSOR_SPECIAL)
	{
		c = peek_cursor(s);
		if (c == '>' || c == '<' || c == '|')
			forward_cursor(s);
		if (c == '>')
		{
			if (peek_cursor(s) == '>')
			{
				forward_cursor(s);
				return (SP_OUT_APPEND);
			}
			return (SP_OUT);
		}
		else if (c == '<')
		{
			if (peek_cursor(s) == '<')
			{
				forward_cursor(s);
				return (SP_IN_HEREDOC);
			}
			return (SP_IN);
		}
		else if (c == '|')
			return (SP_PIPE);
	}
	return (SP_NONE);
}

void	unexpected_eof_matching_error(char quote)
{
	printf("unexpected EOF while looking for matching \'%c\'\n", quote);
	exit(1);
}
void	syntax_error_unexpected_eof(void)
{
	printf("syntax error: unexpected end of file\n");
	exit(1);
}
void	syntax_error_unexpected_token(char *token)
{
	printf("syntax error near unexpected token \'%s\'\n", token);
	exit(1);
}

void	parse_single_quote(t_cursor *s, t_chr_arr *token)
{
	char	c;

	forward_cursor(s);
	while (1)
	{
		c = peek_cursor(s);
		if (c == '\'')
			break ;
		if (!c)
			unexpected_eof_matching_error('\'');
		else
			push_chr_array(token, forward_cursor(s));
	}
	forward_cursor(s);
}

void	parse_double_quote(t_cursor *s, t_chr_arr *token)
{
	char	c;

	forward_cursor(s);
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (c == '\"')
			break ;
		else if (!c)
			unexpected_eof_matching_error('\"');
		else
			push_chr_array(token, forward_cursor(s));
	}
	forward_cursor(s);
}

void	trim_whitespace(t_cursor *s, int expand_env)
{
	char	c;

	while (1)
	{
		if (expand_env)
			c = peek_cursor_with_env(s);
		else
			c = peek_cursor(s);
		if (!c || !ft_isspace(c))
			break ;
		else
			forward_cursor(s);
	}
}

t_token	*parse_next_token(t_cursor *s)
{
	t_token		*ret;
	t_chr_arr	*token;
	char		c;
	int			pushed;

	trim_whitespace(s, 1);
	if (!peek_cursor(s))
		return (NULL);
	ret = malloc(sizeof(t_token));
	ret->s = NULL;
	ret->next = NULL;
	ret->type = SP_NONE;
	if (is_special(s, peek_cursor(s)))
	{
		ret->type = check_special_type(s);
		return (ret);
	}
	token = new_chr_array();
	pushed = 0;
	while (1)
	{
		c = peek_cursor_with_env(s);
		if (!c || ft_isspace(c) || is_special(s, c))
			break ;
		pushed = 1;
		if (c == '\'')
			parse_single_quote(s, token);
		else if (c == '\"')
			parse_double_quote(s, token);
		else
			push_chr_array(token, forward_cursor(s));
	}
	// printf("parsed: pushed %d, token raw \"%s\"\n", pushed, token->arr);
	if (pushed)
		ret->s = copy_chr_arr_to_string(token);
	else
	{
		free(ret);
		ret = NULL;
	}
	delete_chr_array(token);
	// printf("parsed token \"%s\"\n", ret->s);
	return (ret);
}


t_io_file	make_io_file(t_special_type type, char *s/*move ownership*/)
{
	t_io_file	ret;

	ret.fd = -1;
	ret.str = s;
	if (type == SP_IN)
	{
		ret.type = IO_IN_FILE;
	}
	else if (type == SP_IN_HEREDOC)
	{
		ret.type = IO_IN_HEREDOC;
		free(ret.str);
		ret.str = NULL;
		printf("unimplemented: heredoc\n");
	}
	else if (type == SP_OUT)
	{
		ret.type = IO_OUT_TRUNC;
	}
	else if (type == SP_OUT_APPEND)
	{
		ret.type = IO_OUT_APPEND;
	}
	return (ret);
}

t_parse_result	parse_single_command(t_cursor *s, t_str_arr *args, t_io_arr *io)
{
	t_token	*token;
	t_token	*tmp;

	while (1)
	{
		token = parse_next_token(s);
		if (!token)
			return (RES_END);
		if (token->type == SP_PIPE)
		{
			free(token);
			return (RES_PIPE) ;
		}
		else if (token->type == SP_IN || token->type == SP_IN_HEREDOC
			|| token->type == SP_OUT || token->type == SP_OUT_APPEND)
		{
			tmp = parse_next_token(s);
			if (tmp->type != SP_NONE)
				syntax_error_unexpected_token("");
			// printf("io: filename %s\n", tmp->s);
			t_io_file tmpfile = make_io_file(token->type, tmp->s);
			// printf("io file %d, name %s\n", (int)tmpfile.type, tmpfile.str);
			// push_io_array(io, prepare_io_type(tmp->type, tmp->s));
			push_io_array(io, tmpfile);
			free(tmp);
			free(token);
		}
		else
		{
			push_str_array(args, token->s);
			free(token);
		}
	}
	return (RES_ONGOING);
}

t_cmd_arr	*parse_line(char *line)
{
	t_cursor		s;
	t_cmd_arr		*cmds;
	t_command		tmp_cmd;
	t_parse_result	parse_result;
	t_parse_result	last_result;

	init_cursor(&s, line);
	cmds = new_cmd_array();
	last_result = RES_ONGOING;
	while (1)
	{
		init_command(&tmp_cmd);
		// printf("new command\n");
		parse_result = parse_single_command(&s, tmp_cmd.token, tmp_cmd.io);
		if (last_result == RES_PIPE 
			&& tmp_cmd.io->size == 0 && tmp_cmd.token->size == 0)
		{
			if (parse_result == RES_END)
				syntax_error_unexpected_eof();
			else
				syntax_error_unexpected_token("");
		}
		last_result = parse_result;
		push_cmd_array(cmds, tmp_cmd);
		if (parse_result == RES_END)
		{
			// destruct_command(&tmp_cmd);
			break ;
		}
	}
	delete_cursor(&s);
	return (cmds);
}
