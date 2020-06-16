/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:18:09 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/15 18:02:35 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	otr(int d)
{
	if (d < 0)
		return (-d);
	return (d);
}

static int	size(int a, int defin)
{
	int	len;

	len = 1;
	while (a / 10 != 0)
	{
		a /= 10;
		len++;
	}
	if (defin > 2147483646)
		defin = 2147483646;
	if (defin > len)
		len = defin;
	return (len);
}

char		*ft_itoa_d_i(int d, int defin)
{
	char	*resu;
	int		index;
	int		len;

	index = 0;
	len = size(d, defin);
	if (d < 0)
		len++;
	if (!(resu = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (index < len)
		resu[index++] = '0';
	if (d < 0)
		resu[0] = '-';
	resu[len] = '\0';
	while (d / 10 != 0)
	{
		resu[len - 1] = otr(d % 10) + '0';
		d /= 10;
		len--;
	}
	resu[len - 1] = otr(d % 10) + '0';
	len--;
	return (resu);
}
