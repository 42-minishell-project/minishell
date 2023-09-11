/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:17:04 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 11:25:58 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "utils/io_array.h"

void	prepare_io(t_io_arr *io);
int		prepare_io_noexcept(t_io_arr *io);

#endif
