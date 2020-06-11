/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:41:45 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/11 17:01:24 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	size(unsigned long int a, int defin)
{
	int	len;

	len = 1;
	while (a / 16 != 0)
	{
		a /= 16;
		len++;
	}
	if (defin > 2147483646)
		defin = 2147483646;
	if (defin > len)
		len = defin;
	len += 2;
	return (len);
}

char		*ft_itoa_p(void *p, int defin)
{
	char				*resu;
	int					index;
	int					len;
	unsigned long int	a;

	index = 0;
	a = (unsigned long int)p;
	len = size(a, defin);
	if (!(resu = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (index < len)
	{
		resu[index] = '0';
		index++;
	}
	resu[1] = 'x';
	resu[len] = '\0';
	while (a / 16 != 0)
	{
		resu[len] = "0123456789abcdef"[a % 16];
		a /= 16;
		len--;
	}
	resu[len] = "0123456789abcdef"[a % 16];
	len--;
	return (resu);
}
