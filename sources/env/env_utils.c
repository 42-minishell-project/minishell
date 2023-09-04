/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hong-yeonghwan <hong-yeonghwan@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:18:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/02 14:05:17 by hong-yeongh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "env/env_utils.h"
#include "utils/utils.h"

t_env	*get_env_list_head(void)
{
	static t_env	dummy_head;

	return (&dummy_head);
}

t_env	**get_env_list_tail(void)
{
	static t_env	*tail;

	return (&tail);
}

t_env	*find_previous_by_name(char *name)
{
	t_env	*cur;

	cur = get_env_list_head();
	while (cur->next)
	{
		if (ft_strcmp(name, cur->next->name) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	split_envstr(char *env, char **name, char **value)
{
	char	*delimiter;

	delimiter = ft_strchr(env, '=');
	if (!delimiter)
		return ;
	*name = ft_strndup(env, delimiter - env);
	*value = ft_strdup(delimiter + 1);
}
