/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:05:50 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/09 21:02:26 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "env/env_deque.h"

t_env_node	*new_node(char *name, char *value);
void		delete_node(t_env_node *node);

t_env_deque	*get_env_deque(void);
t_env_node	*find_env_node(t_env_deque *envs, char *name);
void		replace_env_node_value(t_env_node *node, char *value);

#endif
