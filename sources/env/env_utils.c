/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:18:21 by jimlee            #+#    #+#             */
/*   Updated: 2023/09/11 12:20:06 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "utils/utils.h"

int	parse_identifier(char *s, char **name, char **value)
{
	int	idx;

	if (name && value)
	{
		*name = NULL;
		*value = NULL;
	}
	if (!(ft_isalpha(s[0]) || s[0] == '_'))
		return (0);
	idx = 0;
	while (ft_isalnum(s[idx]) || (s[idx] == '_'))
		idx++;
	if (s[idx] == '\0')
		return (1);
	else if (s[idx] == '=')
	{
		if (name && value)
		{
			*name = ft_strndup(s, idx);
			*value = ft_strdup(&s[idx + 1]);
		}
		return (2);
	}
	return (0);
}
