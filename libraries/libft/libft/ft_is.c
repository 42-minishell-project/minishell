/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:01:13 by jimlee            #+#    #+#             */
/*   Updated: 2023/05/01 15:21:48 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else if ('a' <= c && c <= 'z')
		return (2);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (4);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else if ('a' <= c && c <= 'z')
		return (2);
	else if ('0' <= c && c <= '9')
		return (4);
	else
		return (0);
}

int	ft_isascii(int c)
{
	return (0x00 <= c && c <= 0x7f);
}

int	ft_isprint(int c)
{
	return (0x20 <= c && c <= 0x7e);
}
