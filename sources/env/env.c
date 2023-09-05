/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/05 13:23:31 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env/env.h"
#include "env/env_utils.h"

#include <stdlib.h>
/*
void	add_new_env(char *name, char *value)
{
	t_env	*tail;
	t_env	*node;

	node = malloc(sizeof(t_env));
	node->name = ft_strdup(name);
	node->value = ft_strdup(value);
	node->next = NULL;
	tail = *get_env_list_tail();
	tail->next = node;
	*get_env_list_tail() = node;
}

void	delete_env_by_name(char *name)
{
	t_env	*prev;
	t_env	*deleted;

	prev = find_previous_by_name(name);
	if (prev)
	{
		deleted = prev->next;
		prev->next = deleted->next;
		if (*get_env_list_tail() == deleted)
			*get_env_list_tail() = prev;
		free(deleted->name);
		free(deleted->value);
		free(deleted);
	}
}

char	*find_env_by_name(char *name)
{
	t_env	*prev;

	prev = find_previous_by_name(name);
	if (prev)
		return (prev->next->value);
	else
		return (NULL);
}
*/

void	update_env(char *name, char *value)
// add env (update value if exists)
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
}

void	delete_env(char *name)
{
	t_env_deque	*env;
	t_env_node	*node;

	env = get_env_deque();
	node = find_env_node(env, name);
	if (!node)
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
}

char	*find_env(char *name)
{
	t_env_node	*node;

	node = find_env_node(get_env_deque(), name);
	if (node)
		return (node->value);
	else
		return (NULL);
}


void	init_envs(char **envp)
{
	int		idx;
	char	*name;
	char	*value;

	// *get_env_list_tail() = get_env_list_head();
	idx = 0;
	while (envp[idx])
	{
		name = NULL;
		value = NULL;
		split_envstr(envp[idx], &name, &value);
		if (name && value)
			update_env(name, value);
			// add_new_env(name, value);
		free(name);
		free(value);
		idx++;
	}
}

char	**get_envp(void)
{
	t_env_node	*node;
	char		**ret;
	int			idx;
	int			len_name;
	int			len_value;

	node = get_env_deque()->head;
	ret = calloc(get_env_deque()->size + 1, sizeof(char *));
	idx = 0;
	while (node)
	{
		len_name = ft_strlen(node->name);
		len_value = ft_strlen(node->value);
		ret[idx] = calloc(len_name + len_value + 2, sizeof(char));
		ft_memcpy(ret[idx], node->name, len_name);
		ret[idx][len_name] = '=';
		ft_memcpy(ret[idx] + (len_name + 1), node->value, len_value);
		idx++;
		node = node->next;
	}
	return (ret);
}

