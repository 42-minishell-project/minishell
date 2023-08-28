/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:38:14 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 21:25:30 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_types.h"

int	parse_prec_pad_hex(t_format *format, long long num, t_fhex *parsed)
{
	int	abs_num_len;
	int	num_len;

	abs_num_len = 0;
	if (num >= 0)
		abs_num_len = get_len_num(num, 16);
	num_len = abs_num_len;
	if ((format->flag & PRECISION) && (format->precision > abs_num_len))
	{
		num_len = format->precision;
		parsed->mid_zero = num_len - abs_num_len;
	}
	if (parsed->prefix)
		num_len += ft_strlen(parsed->prefix);
	if (format->min_width > num_len)
	{
		if (format->flag & LEFT_ALIGN)
			parsed->post_pad = format->min_width - num_len;
		else if ((parsed->mid_zero == 0) && (format->flag & PAD_ZERO))
			parsed->mid_zero = format->min_width - num_len;
		else
			parsed->pre_pad = format->min_width - num_len;
	}
	return (ft_max(num_len, format->min_width));
}

int	print_hex_format(long long num, t_fhex *format, char *base)
{
	if (format->pre_pad && (put_n_times(' ', format->pre_pad) == -1))
		return (-1);
	if (format->prefix && (ft_putstr(format->prefix) == -1))
		return (-1);
	if (format->mid_zero && (put_n_times('0', format->mid_zero) == -1))
		return (-1);
	if (num >= 0 && (ft_putnbr_base(num, base) == -1))
		return (-1);
	if (format->post_pad && (put_n_times(' ', format->post_pad) == -1))
		return (-1);
	return (0);
}

int	print_hex_lower(t_format *format, va_list ap)
{
	long long	val;
	int			put_size;
	t_fhex		parsed;

	val = va_arg(ap, unsigned int);
	ft_memset(&parsed, 0, sizeof(parsed));
	if ((format->flag & PRECISION) && (format->precision == 0) && (val == 0))
		val = -1;
	if ((format->flag & SHARP) && (val > 0))
		parsed.prefix = "0x";
	put_size = parse_prec_pad_hex(format, val, &parsed);
	if (print_hex_format(val, &parsed, "0123456789abcdef") == -1)
		return (-1);
	return (put_size);
}

int	print_hex_upper(t_format *format, va_list ap)
{
	long long	val;
	int			put_size;
	t_fhex		parsed;

	val = va_arg(ap, unsigned int);
	ft_memset(&parsed, 0, sizeof(parsed));
	if ((format->flag & PRECISION) && (format->precision == 0) && (val == 0))
		val = -1;
	if ((format->flag & SHARP) && (val > 0))
		parsed.prefix = "0X";
	put_size = parse_prec_pad_hex(format, val, &parsed);
	if (print_hex_format(val, &parsed, "0123456789ABCDEF") == -1)
		return (-1);
	return (put_size);
}
