/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:05:50 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/04 13:07:04 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

typedef struct s_env_node
{
	char				*name;
	char				*value;
	struct s_env_node	*next;
	struct s_env_node	*prev;
}	t_env_node;

typedef struct s_env_deque
{
	t_env_node	*head;
	t_env_node	*tail;
	int		size;
}	t_env_deque;

// t_env	*get_env_list_head(void);
// t_env	**get_env_list_tail(void);
t_env_node	*new_node(char *name, char *value);
t_env_node	*delete_node(t_env_node *node);

t_env_deque	*get_env_deque(void);
t_env_node	*find_env_node(t_env_deque *envs, char *name);
void		replace_env_node_value(t_env_node *node, char *value);

void		split_envstr(char *env, char **name, char **value);

#endif
