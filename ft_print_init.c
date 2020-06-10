/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:14:22 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/10 18:13:15 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_parsing	ft_flag_init(void)
{
	t_parsing	flag;

	flag.zero = 0;
	flag.minus = 0;
	flag.width = 0;
	flag.dot = 0;
	flag.precision = 0;
	flag.specifier = 0;
	return (flag);
}

int			ft_not_flag(char str)
{
	if (str == 'c' || str == 's' || str == 'p' || str == 'd' || str == 'i' ||
		str == 'u' || str == 'x' || str == 'X' || str == '%')
		return (1);
	return (0);
}
