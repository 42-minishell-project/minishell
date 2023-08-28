/*

char	*split_pipe_single_command(char **start)
{
	char	*s;
	char	*ret;
	char	end;
	int		size;

	printf("split single start from %s\n", *start);
	s = *start;
	end = -1;
	if (!*s)
		return (NULL);
	while (*s)
	{
		if ((end > 0) && (*s == end))
			end = -1;
		else
		{
			if (*s == '|')
				break ;
			if (*s == '\"')
				end = '\"';
			else if (*s == '\'')
				end = '\'';
		}
		s++;
	}
	if (end > 0)
		unexpected_eof_error(end);
	size = s - *start;
	ret = ft_strndup(*start, size);
	if (*s == '|')
		s++;
	*start = s;
	return (ret);
}

t_str_arr	*split_by_pipes(char *s)
{
	t_str_arr	*ret;
	char		*cmd;

	ret = new_str_array();
	while (1)
	{
		cmd = split_pipe_single_command(&s);
		if (!cmd)
			break ;
		push_str_array(ret, cmd);
	}
	return (ret);
}

char	*parse_next_token(t_cursor *s)
{
	char		*ret;
	t_chr_arr	*token;
	char		c;
	int			pushed;

	trim_whitespace(s, 1);
	// printf("out, c \'%c\'\n", peek_cursor(s));
	if (!peek_cursor(s))
		return (NULL);
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
	ret = NULL;
	if (pushed)
		ret = copy_chr_arr_to_string(token);
	delete_chr_array(token);
	return (ret);
}

void	handle_io(t_io_arr *io, t_special_type type, char *name)
{
	t_io_file	file;

	file.fd = -1;
	file.str = NULL;
	file.type = IO_NONE;

}

*/
