/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:05:47 by jimlee            #+#    #+#             */
/*   Updated: 2023/03/04 21:52:06 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PRINT_H
# define FORMAT_PRINT_H

# include <stdlib.h>
# include <stdarg.h>
# include "format.h"
# include "format_parser.h"
# include "libft.h"

int	print_argument(t_format *format, va_list ap);
int	print_format(const char *s, va_list ap, int *idx_ptr);

#endif
