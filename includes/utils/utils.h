/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:40:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/08/23 15:18:23 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UITLS_H
# define UTILS_H

# include <stdlib.h>

char	*ft_strndup(const char *s, size_t n);
void	free_2d_str_array(char **null_terminated_str_array);

#endif
