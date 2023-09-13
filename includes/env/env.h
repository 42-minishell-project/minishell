/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/13 20:06:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

void	init_envs(char **envp);
char	**get_envp(void);
void	update_env(const char *name, const char *value);
void	delete_env(const char *name);
char	*find_env(const char *name);

char	**get_env_path(void);
void	update_env_path(const char *path_str);

int		parse_identifier(const char *s, char **name, char **value);

#endif
