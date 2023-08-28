/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:55:36 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 23:45:44 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || (c == 32));
}

int	ft_atoi(const char *nptr)
{
	int	idx;
	int	sign;
	int	ret;

	idx = 0;
	while (ft_isspace(nptr[idx]))
		idx++;
	sign = 1;
	if ((nptr[idx] == '-') || (nptr[idx] == '+'))
	{
		if (nptr[idx] == '-')
			sign = -sign;
		idx++;
	}
	ret = 0;
	while (ft_isdigit(nptr[idx]))
	{
		ret *= 10;
		ret += sign * (nptr[idx] - '0');
		idx++;
	}
	return (ret);
}

static int	get_len_num_str(int n)
{
	int	len_num;

	len_num = 0;
	if (n <= 0)
		len_num++;
	while (n)
	{
		n /= 10;
		len_num++;
	}
	return (len_num);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		idx;
	int		len_num;
	char	*num_str;

	len_num = get_len_num_str(n);
	num_str = (char *)malloc(sizeof(char) * (len_num + 1));
	if (!num_str)
		return (NULL);
	num_str[len_num] = '\0';
	idx = len_num - 1;
	if (n < 0)
		num_str[0] = '-';
	else if (n == 0)
		num_str[0] = '0';
	while (n)
	{
		num_str[idx] = ft_abs(n % 10) + '0';
		n /= 10;
		idx--;
	}
	return (num_str);
}
