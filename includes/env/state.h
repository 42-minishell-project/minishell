/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:40:20 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 16:50:41 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "env/env_deque.h"

typedef struct s_env_state
{
	t_env_deque	q;
	char		**paths;
	char		*exit_code_str;
}	t_env_state;

#endif
