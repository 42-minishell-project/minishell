/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_types.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:33:25 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 21:59:43 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_TYPES_H
# define F_TYPES_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "format/format.h"
# include "utils/utils.h"
# include "libft.h"

int	print_invalid(t_format *format, va_list ap);
int	print_percent(t_format *format, va_list ap);
int	print_char(t_format *format, va_list ap);
int	print_str(t_format *format, va_list ap);
int	print_hex_lower(t_format *format, va_list ap);
int	print_hex_upper(t_format *format, va_list ap);
int	print_ptr(t_format *format, va_list ap);
int	print_dec(t_format *format, va_list ap);
int	print_int(t_format *format, va_list ap);
int	print_uint(t_format *format, va_list ap);

typedef struct s_fdec
{
	int		pre_pad;
	char	sign;
	int		mid_zero;
	int		post_pad;
}			t_fdec;

typedef struct s_fhex
{
	int		pre_pad;
	char	*prefix;
	int		mid_zero;
	int		post_pad;
}			t_fhex;

typedef struct s_fstr
{
	int		pre_pad;
	int		size;
	int		post_pad;
}			t_fstr;

#endif
