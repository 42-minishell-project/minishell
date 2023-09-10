/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:50:16 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/10 15:54:30 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_special_type
{
	SP_NONE = 0,
	SP_IN = 1,
	SP_IN_HEREDOC = 2,
	SP_OUT = 3,
	SP_OUT_APPEND = 4,
	SP_PIPE = 5
}	t_special_type;

typedef struct s_token
{
	char			*s;
	t_special_type	type;
}	t_token;

typedef enum e_parse_result
{
	RES_START = 0,
	RES_END = 1,
	RES_PIPE = 2,
	RES_ERROR = 3
}	t_parse_result;

#endif
