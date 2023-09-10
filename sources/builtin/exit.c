/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:51:10 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/10 14:38:50 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/builtin_error.h"

static int	check_long_long_atoi(char *str, long long sum, int i, int sign)
{
	if (sign == 1)
	{
		if (i == 17 && str[i + 1])
		{
			if (sum > 922337203685477580 && (str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
			if (sum == 922337203685477580 && (str[i + 1] > '7' && str[i + 1] <= '9'))
				return (1);
		}
		if (i == 19)
			return (1);
	}
	else
	{
		if (i == 18 && str[i + 1])
		{
			if (sum > 922337203685477580 && (str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
			if (sum == 922337203685477580 && (str[i + 1] > '8' && str[i + 1] <= '9'))
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

static int	is_number(char *str)
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
		{
			exit(sum % 256);
		}
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
	{
		// ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	else if (argc == 2)
	{
		// ft_putstr_fd("exit\n", 1);
		if (!is_number(argv[1]))
		{
			exit_error_numeric(argv[1]);
		}
			// exit(builtin_error("exit", argv[1], "numeric argument required", 255));
		else
			run_exit_number(argv[1]);
	}
	else
	{
		if (!is_number(argv[1]))
			exit_error_numeric(argv[1]);
		else
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
			exit(1);
		}
	}
}
