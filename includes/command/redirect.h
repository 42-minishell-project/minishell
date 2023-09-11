/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:56:07 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:32:02 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "utils/io_array.h"

void	prepare_io(t_io_arr *io);
int		prepare_io_noexcept(t_io_arr *io);

#endif
