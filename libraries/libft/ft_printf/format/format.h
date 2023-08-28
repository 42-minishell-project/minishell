/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:16 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:42:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

typedef enum e_ftype
{
	INVALID = 0,
	CHAR,
	STR,
	PTR,
	DEC,
	INT,
	UINT,
	HEX_LOWER,
	HEX_UPPER,
	PERCENT
}	t_ftype;

typedef enum e_flag
{
	LEFT_ALIGN = 1 << 0,
	SHOW_POS_SIGN = 1 << 1,
	SHOW_POS_BLANK = 1 << 2,
	PAD_ZERO = 1 << 3,
	SHARP = 1 << 4,
	PRECISION = 1 << 5
}	t_flag;

typedef struct s_format
{
	int		flag;
	int		min_width;
	int		precision;
	t_ftype	type;
}			t_format;

#endif
