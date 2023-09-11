/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_deque.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:35:58 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:16:02 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_DEQUE_H
# define ENV_DEQUE_H

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
	int			size;
}	t_env_deque;

#endif
