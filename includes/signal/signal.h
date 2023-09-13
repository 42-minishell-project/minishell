/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:33:15 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/13 20:09:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

void	sigquit_handler(int signo);
void	sigint_run_handler(int signo);
void	sigint_enter_handler(int signo);

#endif
