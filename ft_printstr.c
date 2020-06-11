/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:53:00 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/11 15:05:25 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			ft_space(t_parsing flag, int len)
{
	int	count;

	count = 0;
	if (flag.width < 0)
		flag.width = -flag.width;
	while (flag.width-- > len)
	{
		if (flag.zero == 1 && flag.minus == 0)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	return (count);
}

int					ft_printchar(char c, t_parsing flag)
{
	int	count;

	count = 0;
	if (flag.minus == 1 || flag.width < -1)
	{
		count += write(1, &c, 1);
		count += ft_space(flag, 1);
	}
	else
	{
		count += ft_space(flag, 1);
		count += write(1, &c, 1);
	}
	return (count);
}

static t_parsing	ft_determine_width(t_parsing flag, int *len)
{
	if (flag.width < 0)
		flag.minus = 1;
	if (flag.precision < 0)
		flag.dot = 0;
	if (*len > flag.precision && flag.specifier == 's' && flag.dot)
		*len = flag.precision;
	return (flag);
}

int					ft_printstr(char *str, t_parsing flag)
{
	int	count;
	int	len;

	if (str == NULL)
		return (ft_printstr("null", flag));
	count = 0;
	len = ft_strlen(str);
	flag = ft_determine_width(flag, &len);
	if (flag.minus == 0)
	{
		count += ft_space(flag, len);
		count += write(1, str, len);
	}
	if (flag.minus == 1)
	{
		count += write(1, str, len);
		count += ft_space(flag, len);
	}
	return (count);
}
