/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/06 17:41:14 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

// void	add_new_env(char *name, char *value);


void	update_env(char *name, char *value);
void	delete_env(char *name);
char	*find_env(char *name);
// void	delete_env_by_name(char *name);
// char	*find_env_by_name(char *name);
void	init_envs(char **envp);

char	**get_envp(void);
int		parse_identifier(char *s, char **name, char **value);

char	**get_env_path(void);
void	update_env_path(char *path_str);
char	*get_last_exit_code(void);
void	update_last_exit_code(int exit_code);

#endif
