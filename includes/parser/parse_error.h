/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:43:32 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 19:38:57 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ERROR_H
# define PARSE_ERROR_H

int	unexpected_eof_matching_error(char quote);
int	syntax_error_unexpected_eof(void);
int	syntax_error_unexpected_token(char *token);

#endif
