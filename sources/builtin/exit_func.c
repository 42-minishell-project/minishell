/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:19:12 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 16:26:28 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_long_num(char *str, int standard, int i, int sum)
{
	if (i == 17 && str[i + 1])
	{
		if (sum > standard && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
		if (sum == standard && (str[i + 1] > '7' && str[i + 1] <= '9'))
			return (1);
	}
	return (0);
}
