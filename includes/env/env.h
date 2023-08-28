/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/21 03:13:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

void	add_new_env(char *name, char *value);
void	delete_env_by_name(char *name);
char	*find_env_by_name(char *name);
void	init_envs(char **envp);

#endif
