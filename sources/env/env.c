/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:18 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/02 14:26:08 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env/env.h"
#include "env/env_utils.h"
#include "libft/libft.h"
#include <stdlib.h>

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

void	init_envs(char **envp)
{
	int		idx;
	char	*name;
	char	*value;

	*get_env_list_tail() = get_env_list_head();
	idx = 0;
	while (envp[idx])
	{
		name = NULL;
		value = NULL;
		split_envstr(envp[idx], &name, &value);
		if (name && value)
			add_new_env(name, value);
		free(name);
		free(value);
		idx++;
	}
}



