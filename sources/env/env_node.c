/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:06:36 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:33:55 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env_utils.h"

t_env_deque	*get_env_deque(void)
{
	static t_env_deque	env;

	return (&env);
}

t_env_node	*new_node(const char *name, const char *value)
{
	t_env_node	*ret;

	ret = malloc(sizeof(t_env_node));
	ret->name = ft_strdup(name);
	ret->value = ft_strdup(value);
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

void	delete_node(t_env_node *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

t_env_node	*find_env_node(t_env_deque *envs, const char *name)
{
	t_env_node	*cur;

	cur = envs->head;
	while (cur)
	{
		if (ft_strcmp(cur->name, name) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	replace_env_node_value(t_env_node *node, const char *value)
{
	free(node->value);
	node->value = ft_strdup(value);
}
