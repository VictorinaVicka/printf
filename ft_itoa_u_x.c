/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 10:14:57 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/10 17:10:25 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	size(unsigned int a, int system, int defin)
{
	size_t	len;

	len = 1;
	while (a / system != 0)
	{
		a /= system;
		len++;
	}
	if (defin > 2147483646)
		defin = 2147483646;
	if (defin > len)
		len = defin;
	return (len);
}

char	*ft_itoa_u_x(unsigned int n, int system, int defin)
{
	char	*resu;
	size_t	index;
	size_t	len;

	index = 0;
	if (system < 2 || system > 16)
		return (NULL);
	len = size(n, system, defin);
	if (!(resu = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (index < len)
	{
		resu[index] = '0';
		index++;
	}
	resu[len] = '\0';
	while (n / system != 0)
	{
		resu[len - 1] = "0123456789abcdef"[n % system];
		n /= system;
		len--;
	}
	resu[len - 1] = "0123456789abcdef"[n % system];
	len--;
	return (resu);
}
