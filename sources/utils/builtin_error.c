/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeohong <yeohong@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:45:18 by yeohong           #+#    #+#             */
/*   Updated: 2023/09/05 14:40:41 by yeohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils/builtin_error.h"
#include "libft/libft.h"

int    print_cd_error(char *path, char *message, int error_code)
{  
    ft_putstr_fd("bash: cd: ", 2);
    ft_putstr_fd(path, 2);
    ft_putstr_fd(message, 2);
    ft_putchar_fd('\n', 2);
    return (error_code);
}