/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/12 10:15:37 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env.h"
#include "env/env_utils.h"

void	update_env(const char *name, const char *value)
{
	t_env_deque	*env;
	t_env_node	*node;

	env = get_env_deque();
	node = find_env_node(env, name);
	if (node)
	{
		replace_env_node_value(node, value);
	}
	else
	{
		node = new_node(name, value);
		if (env->tail)
			env->tail->next = node;
		else
			env->head = node;
		node->prev = env->tail;
		env->tail = node;
		env->size++;
	}
	if (ft_strcmp(name, "PATH") == 0)
		update_env_path(value);
}

void	delete_env(const char *name)
{
	t_env_deque	*env;
	t_env_node	*node;

	env = get_env_deque();
	node = find_env_node(env, name);
	if (node)
	{
		if (node->prev)
			node->prev->next = node->next;
		else
			env->head = node->next;
		if (node->next)
			node->next->prev = node->prev;
		else
			env->tail = node->prev;
		env->size--;
		delete_node(node);
	}
	if (ft_strcmp(name, "PATH") == 0)
		update_env_path(NULL);
}

char	*find_env(const char *name)
{
	t_env_node	*node;

	node = find_env_node(get_env_deque(), name);
	if (node)
		return (node->value);
	else
		return (NULL);
}

char	**get_envp(void)
{
	t_env_node	*node;
	char		**ret;
	int			idx;
	int			len_name;
	int			len_value;

	node = get_env_deque()->head;
	ret = ft_calloc(get_env_deque()->size + 1, sizeof(char *));
	idx = 0;
	while (node)
	{
		len_name = ft_strlen(node->name);
		len_value = ft_strlen(node->value);
		ret[idx] = ft_calloc(len_name + len_value + 2, sizeof(char));
		ft_memcpy(ret[idx], node->name, len_name);
		ret[idx][len_name] = '=';
		ft_memcpy(ret[idx] + (len_name + 1), node->value, len_value);
		idx++;
		node = node->next;
	}
	return (ret);
}
