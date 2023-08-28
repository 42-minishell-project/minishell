/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:29:29 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/09 18:36:02 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	decimal;
	long long	n_int64;
	int			digit;

	n_int64 = (long long)n;
	if (n_int64 < 0)
	{
		ft_putchar_fd('-', fd);
		n_int64 = -n_int64;
	}
	decimal = 1;
	while (n_int64 / decimal >= 10)
		decimal = decimal * 10;
	while (decimal > 0)
	{
		digit = n_int64 / decimal;
		ft_putchar_fd(digit + '0', fd);
		n_int64 -= digit * decimal;
		decimal = decimal / 10;
	}
}
