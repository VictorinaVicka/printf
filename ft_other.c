/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 17:15:15 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/15 17:34:22 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_width(const char **str, va_list argptr)
{
	int	width;

	width = 0;
	if (**str == '*')
		width = va_arg(argptr, int);
	if (ft_isdigit(**str))
	{
		width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
		(*str)--;
	}
	return (width);
}

int	ft_precision(const char **str, va_list argptr)
{
	int	precision;

	precision = 0;
	if (*(*str + 1) == '*')
	{
		(*str)++;
		precision = va_arg(argptr, int);
	}
	if (ft_isdigit(*(*str + 1)))
	{
		(*str)++;
		precision = ft_atoi(*str);
		while (ft_isdigit(*(*str + 1)))
			(*str)++;
	}
	return (precision);
}
