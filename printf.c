/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:28:00 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/08 17:38:32 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// counte -  число напечатанных символов
static int	ft_transform(va_list argptr, t_parsing flag)
{
	if (flag.specifier == 'c')
		return (ft_printchar(va_arg(argptr, int), flag));
	else if (flag.specifier == 's')
		return (ft_printstr(va_arg(argptr, char*), flag));
	else if (flag.specifier == 'p')
		return ();
	else if (flag.specifier == 'd' || flag.specifier 'i')
		return ();
	else if (flag.specifier == 'u')
		return ();
	else if (flag.specifier == 'x' || flag.specifier == 'X')
		return ();
	else if (flag.specifier == '%')
		return (ft_printchar('%', flag));
	else
		return (ft_printchar(flag.specifier, flag));
	return (0);
}

int	ft_printf(const char *str, ...)
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
			count += ft_transform(argptr, )

	}
	va_end(argptr);
	return (count);
}