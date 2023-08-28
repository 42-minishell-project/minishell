/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:52:43 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 21:12:46 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	ft_putchar_n(const char *buffer, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		if (ft_putchar(buffer[idx]) == -1)
			return (-1);
		idx++;
	}
	return (idx);
}

int	print_str_format(char *buffer, t_fstr *format)
{
	if (format->pre_pad)
	{
		if (put_n_times(' ', format->pre_pad) == -1)
			return (-1);
	}
	if (ft_putchar_n(buffer, format->size) == -1)
		return (-1);
	if (format->post_pad)
	{
		if (put_n_times(' ', format->post_pad) == -1)
			return (-1);
	}
	return (0);
}

int	print_char(t_format *format, va_list ap)
{
	char	val;
	t_fstr	parsed;

	val = va_arg(ap, int);
	ft_memset(&parsed, 0, sizeof(parsed));
	parsed.size = 1;
	if (format->min_width > 1)
	{
		if (format->flag & LEFT_ALIGN)
			parsed.post_pad = format->min_width - 1;
		else
			parsed.pre_pad = format->min_width - 1;
	}
	if (print_str_format(&val, &parsed) == -1)
		return (-1);
	return (ft_max(1, format->min_width));
}

int	print_str(t_format *format, va_list ap)
{
	char	*val;
	t_fstr	parsed;

	val = va_arg(ap, char *);
	ft_memset(&parsed, 0, sizeof(parsed));
	if (!val)
		val = "(null)";
	parsed.size = ft_strlen(val);
	if ((format->flag & PRECISION) && (parsed.size > format->precision))
		parsed.size = format->precision;
	if (format->min_width > parsed.size)
	{
		if (format->flag & LEFT_ALIGN)
			parsed.post_pad = format->min_width - parsed.size;
		else
			parsed.pre_pad = format->min_width - parsed.size;
	}
	if (print_str_format(val, &parsed) == -1)
		return (-1);
	return (ft_max(parsed.size, format->min_width));
}
