/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:03 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/01 13:48:08 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parser.h"

int	parse_flag(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (ft_strchr("-0# +", s[idx]))
		{
			if (s[idx] == '-')
				format->flag |= LEFT_ALIGN;
			else if (s[idx] == '0')
				format->flag |= PAD_ZERO;
			else if (s[idx] == '#')
				format->flag |= SHARP;
			else if (s[idx] == ' ')
				format->flag |= SHOW_POS_BLANK;
			else if (s[idx] == '+')
				format->flag |= SHOW_POS_SIGN;
		}
		else
			break ;
		idx++;
	}
	return (idx);
}

int	parse_width(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	while (ft_isdigit(s[idx]))
	{
		format->min_width *= 10;
		format->min_width += s[idx] - '0';
		idx++;
	}
	return (idx);
}

int	parse_precision(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	if (s[idx] == '.')
	{
		idx++;
		format->flag |= PRECISION;
		while (ft_isdigit(s[idx]))
		{
			format->precision *= 10;
			format->precision += s[idx] - '0';
			idx++;
		}
	}
	return (idx);
}

int	parse_format(const char *s, t_format *format)
{
	if (s[0] == 'c')
		format->type = CHAR;
	else if (s[0] == 's')
		format->type = STR;
	else if (s[0] == 'p')
		format->type = PTR;
	else if (s[0] == 'd')
		format->type = DEC;
	else if (s[0] == 'i')
		format->type = INT;
	else if (s[0] == 'u')
		format->type = UINT;
	else if (s[0] == 'x')
		format->type = HEX_LOWER;
	else if (s[0] == 'X')
		format->type = HEX_UPPER;
	else if (s[0] == '%')
		format->type = PERCENT;
	else
	{
		format->type = INVALID;
		return (0);
	}
	return (1);
}

int	parse_format_string(const char *s, t_format *format)
{
	int	idx;

	idx = 0;
	idx += parse_flag(s + idx, format);
	idx += parse_width(s + idx, format);
	idx += parse_precision(s + idx, format);
	idx += parse_format(s + idx, format);
	if (format->flag & PRECISION)
		format->flag &= ~PAD_ZERO;
	if (format->type == INVALID)
		return (-1);
	return (idx);
}
