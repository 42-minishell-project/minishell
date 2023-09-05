/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:18:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/05 13:24:16 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env_utils.h"
#include "utils/utils.h"
/*
t_env_node	*get_env_list_head(void)
{
	static t_env_node	dummy_head;

	return (&dummy_head);
}

t_env_node	**get_env_list_tail(void)
{
	static t_env_node	*tail;

	return (&tail);
}

t_env_node	*find_previous_by_name(char *name)
{
	t_env_node	*cur;

	cur = get_env_list_head();
	while (cur->next)
	{
		if (ft_strcmp(name, cur->next->name) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
*/

void	split_envstr(char *env, char **name, char **value)
{
	char	*delimiter;

	delimiter = ft_strchr(env, '=');
	if (!delimiter)
		return ;
	*name = ft_strndup(env, delimiter - env);
	*value = ft_strdup(delimiter + 1);
}

int	is_valid_identifier(char *s, char **name, char **value)
{
	int	idx;

	if (name && value)
	{
		*name = NULL;
		*value = NULL;
	}
	if (!ft_isalpha(s[0]))
		return (0);
	idx = 0;
	while (ft_isalnum(s[idx]) || (s[idx] == '_'))
		idx++;
	if (s[idx] == '\0')
		return (1);
	else if (s[idx] == '=')
	{
		if (name && value)
		{
			*name = ft_strndup(s, idx);
			*value = ft_strdup(&s[idx + 1]);
		}
		return (2);
	}
	return (0);
}

