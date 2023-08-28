/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:19:21 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:22:57 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(const char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
