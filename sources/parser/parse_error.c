/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:44:12 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/15 18:35:49 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "parser/parse_utils.h"

int	unexpected_eof_matching_error(char quote)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("unexpected EOF while looking for matching `", STDERR_FILENO);
	ft_putchar_fd(quote, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	return (-1);
}

int	syntax_error_unexpected_eof(void)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error: unexpected end of file\n", STDERR_FILENO);
	return (-1);
}

int	syntax_error_unexpected_token(char *token)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("\'\n", STDERR_FILENO);
	return (-1);
}
