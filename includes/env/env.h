/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:02:34 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:32:10 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

void	update_env(const char *name, const char *value);
void	delete_env(const char *name);
char	*find_env(const char *name);
void	init_envs(char **envp);

char	**get_envp(void);
int		parse_identifier(const char *s, char **name, char **value);

char	**get_env_path(void);
void	update_env_path(const char *path_str);

char	*get_last_exit_code(void);
void	update_last_exit_code(int exit_code);

#endif
