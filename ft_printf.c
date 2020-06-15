/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:28:00 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/15 16:22:44 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_parsing	ft_get_form(const char **str, va_list argptr)
{
	t_parsing	flag;

	flag = ft_flag_init();
	(*str)++;
	while (**str != '\0' && !(ft_not_flag(**str)))
	{
		if (**str == '-')
			flag.minus = 1;
		else if (**str == '0' && flag.minus == 0 && flag.zero == 0)
			flag.zero = 1;
		else if (**str == '.')
		{
			flag.dot = 1;
			flag.precision = ft_precision(&(*str), argptr);
		}
		else if (**str == '*' || ft_isdigit(**str))
			flag.width = ft_width(&(*str), argptr);
		else
			break ;
		(*str)++;
	}
	flag.specifier = **str;
	return (flag);
}

static int			ft_transform(va_list argptr, t_parsing flag)
{
	if (flag.specifier == 'c')
		return (ft_printchar(va_arg(argptr, int), flag));
	else if (flag.specifier == 's')
		return (ft_printstr(va_arg(argptr, char*), flag));
	else if (flag.specifier == 'p')
		return (ft_printp(va_arg(argptr, void *), flag));
	else if (flag.specifier == 'd' || flag.specifier == 'i')
		return (ft_print_d_i(va_arg(argptr, int), flag));
	else if (flag.specifier == 'u')
		return (ft_print_u(va_arg(argptr, int), flag));
	else if (flag.specifier == 'x' || flag.specifier == 'X')
		return (ft_print_x(va_arg(argptr, int), flag));
	else if (flag.specifier == '%')
		return (ft_printchar('%', flag));
	else
		return (ft_printchar(flag.specifier, flag));
	return (0);
}

int					ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		params;
	int		count;

	if (str == NULL)
		return (-1);
	va_start(argptr, str);
	count = 0;
	while (*str != '\0')
	{
		params = count;
		if (*str == '%')
			count += ft_transform(argptr, ft_get_form(&str, argptr));
		else
			count += ft_printchar(*str, ft_flag_init());
		if (count < params)
			count = -1;
		if (count < 0 || *str == '\0')
			break ;
		str++;
	}
	va_end(argptr);
	return (count);
}
