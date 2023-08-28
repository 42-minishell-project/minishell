/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:01:08 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:25:03 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_len_num(long long n, int n_base)
{
	int	len_num;

	len_num = 0;
	if (n <= 0)
		len_num++;
	while (n)
	{
		n /= n_base;
		len_num++;
	}
	return (len_num);
}

int	ft_putnbr(long long n)
{
	long long	decimal;
	int			digit;
	char		to_put;

	if (n < 0)
	{
		if (write(STDOUT_FILENO, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	decimal = 1;
	while (n / decimal >= 10)
		decimal = decimal * 10;
	while (decimal > 0)
	{
		digit = n / decimal;
		to_put = digit + '0';
		if (write(STDOUT_FILENO, &to_put, 1) == -1)
			return (-1);
		n -= digit * decimal;
		decimal = decimal / 10;
	}
	return (0);
}

int	ft_putnbr_base(long long num, char *base)
{
	int			n_base;
	int			digit;
	long long	to_div;

	if (num < 0)
	{
		if (write(STDOUT_FILENO, "-", 1) == -1)
			return (-1);
		num = -num;
	}
	n_base = ft_strlen(base);
	to_div = 1;
	while (num / to_div >= n_base)
		to_div = to_div * n_base;
	while (to_div >= 1)
	{
		digit = num / to_div;
		if (write(STDOUT_FILENO, &base[digit], 1) == -1)
			return (-1);
		num -= digit * to_div;
		to_div = to_div / n_base;
	}
	return (0);
}

int	get_len_num_u(unsigned long long n, int n_base)
{
	int	len_num;

	len_num = 0;
	if (n == 0)
		len_num++;
	while (n)
	{
		n /= n_base;
		len_num++;
	}
	return (len_num);
}

int	ft_putnbr_base_u(unsigned long long num, char *base)
{
	int					n_base;
	int					digit;
	unsigned long long	to_div;

	n_base = ft_strlen(base);
	to_div = 1;
	while (num / to_div >= (unsigned long long)n_base)
		to_div = to_div * n_base;
	while (to_div >= 1)
	{
		digit = num / to_div;
		if (write(STDOUT_FILENO, &base[digit], 1) == -1)
			return (-1);
		num -= digit * to_div;
		to_div = to_div / n_base;
	}
	return (0);
}
