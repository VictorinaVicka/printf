/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:47:04 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/10 10:44:48 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printp(void *p, t_parsing flag)
{
	int	count;
	int	definition;
	char	*array;

	count = 0;
	definition = flag.precision;
	if (array == NULL)
		return (-1);
	if (flag.zero)
	{
		definition = flag.width - 2;
		flag.width = 0;
	}
	if (flag.zero && (flag.dot || flag.width < 0 || flag.minus))
		flag.zero = 0;
	if (flag.dot && definition == 0 && p == NULL)
		array = ft_strdup("0x");
	else
		array = ft_itoa_u_i(p, 10, definition);
	count += ft_printstr(array, flag);
	free(array);
	return (count);
}
