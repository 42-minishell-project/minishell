/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:51:10 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 16:25:48 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/builtin_error.h"
#include "utils/utils.h"
#include "builtin/builtin_exit.h"

static int	check_long_long_atoi(char *str, long long sum, int i, int sign)
{
	long long	standard;

	standard = 922337203685477580;
	if (sign == 1)
	{
		if (check_long_num(str, standard, i, sum) == 1)
			return (1);
		if (i == 19)
			return (1);
	}
	else
	{
		if (i == 18 && str[i + 1])
		{
			if (sum > standard && (str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
			if (sum == standard && (str[i + 1] > '8' && str[i + 1] <= '9'))
				return (1);
		}
		if (i == 20)
			return (1);
	}
	return (0);
}

static long long	ft_long_long_atoi(char *str, int i, int *over)
{
	int				sign;
	long long		result;

	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (check_long_long_atoi(str, result, i, sign) == 1)
		{
			*over = 1;
			return ((long long)(sign * result));
		}
		i++;
	}
	return ((long long)(sign * result));
}

void	exit_error_numeric(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	exit(255);
}

static void	run_exit_number(char *str)
{
	long long	sum;
	int			over;
	int			result;

	over = 0;
	sum = ft_long_long_atoi(str, 0, &over);
	if (over == 1)
	{
		exit_error_numeric(str);
	}
	else
	{
		if (sum > 0)
			exit(sum % 256);
		else
		{
			sum = sum % 256;
			sum = sum + 256;
			exit(sum);
		}
	}
}

int	run_exit(int argc, char **argv)
{
	int	over;

	over = 0;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		if (!is_number(argv[1]))
			exit_error_numeric(argv[1]);
		else
			run_exit_number(argv[1]);
	}
	else
	{
		if (!is_number(argv[1]))
			exit_error_numeric(argv[1]);
		else
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", \
				STDERR_FILENO);
			exit(1);
		}
	}
}
