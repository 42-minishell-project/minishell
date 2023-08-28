/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:12:36 by jimlee            #+#    #+#             */
/*   Updated: 2022/12/02 16:15:07 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_print.h"

int	print_format(const char *s, va_list ap, int *idx_ptr)
{
	int			idx;
	int			parsed_size;
	int			ret_size;
	t_format	format;

	idx = *idx_ptr;
	ft_memset(&format, 0, sizeof(format));
	parsed_size = parse_format_string(&s[idx], &format);
	if (parsed_size == -1)
		return (-1);
	ret_size = print_argument(&format, ap);
	*idx_ptr += parsed_size;
	return (ret_size);
}
