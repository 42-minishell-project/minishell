/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_invalid_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:50:24 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 21:25:43 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	print_invalid(t_format *format, va_list ap)
{
	(void)format;
	(void)ap;
	return (0);
}

int	print_percent(t_format *format, va_list ap)
{
	t_fstr	parsed;

	(void)ap;
	ft_memset(&parsed, 0, sizeof(parsed));
	parsed.size = 1;
	if (format->min_width > parsed.size)
	{
		if (format->flag & LEFT_ALIGN)
			parsed.post_pad = format->min_width - parsed.size;
		else
			parsed.pre_pad = format->min_width - parsed.size;
	}
	if (parsed.pre_pad && (put_n_times(' ', parsed.pre_pad) == -1))
		return (-1);
	if (ft_putchar('%') == -1)
		return (-1);
	if (parsed.post_pad && (put_n_times(' ', parsed.post_pad) == -1))
		return (-1);
	return (ft_max(parsed.size, format->min_width));
}
