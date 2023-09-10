/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 02:40:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:59:03 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		is_number(char *str);
char	*ft_strndup(const char *s, size_t n);
void	free_2d_str_array(char **null_terminated_str_array);

#endif
