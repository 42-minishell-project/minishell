/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:56:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/23 14:12:41 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_PATH_H
# define ENV_PATH_H

char	**get_paths(void);
void	init_paths(char **envp);
void	delete_paths(void);
char	*find_executable(char *exe);

#endif
