/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:44:16 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/11 15:06:55 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_parsing	ft_instal_flag(int *definition, int neg_num, t_parsing flag)
{
	if (flag.zero && (flag.minus || flag.width < 0 ||
		(flag.dot && *definition >= 0)))
		flag.zero = 0;
	if (flag.zero)
	{
		*definition = flag.width;
		if (neg_num)
			(*definition)--;
		flag.width = 0;
	}
	return (flag);
}

int					ft_print_d_i(int num, t_parsing flag)
{
	int		count;
	int		definition;
	char	*array;

	count = 0;
	definition = flag.precision;
	if (array == NULL)
		return (-1);
	flag = ft_instal_flag(&definition, num < 0, flag);
	if (flag.dot && definition == 0 && num == 0 && flag.zero == 0)
		array = ft_strdup("");
	else
		array = ft_itoa_u_x(num, 10, definition);
	count = ft_printstr(array, flag);
	free(array);
	return (count);
}

int					ft_print_u(unsigned int num, t_parsing flag)
{
	int		count;
	int		definition;
	char	*array;

	count = 0;
	definition = flag.precision;
	if (array == NULL)
		return (-1);
	flag = ft_instal_flag(&definition, 0, flag);
	if (flag.dot && definition == 0 && num == 0 && flag.zero == 0)
		array = ft_strdup("");
	else
		array = ft_itoa_u_x(num, 10, definition);
	count = ft_printstr(array, flag);
	free(array);
	return (count);
}

int					ft_print_x(unsigned int num, t_parsing flag)
{
	int		count;
	int		definition;
	char	*array;
	int		index;

	count = 0;
	index = -1;
	definition = flag.precision;
	if (array == NULL)
		return (-1);
	flag = ft_instal_flag(&definition, 0, flag);
	if (flag.dot && definition == 0 && num == 0 && flag.zero == 0)
		array = ft_strdup("");
	else
		array = ft_itoa_u_x(num, 16, definition);
	if (flag.specifier == 'X')
		while (array[index])
		{
			array[index] = ft_toupper(array[index]);
			index++;
		}
	count = ft_printstr(array, flag);
	free(array);
	return (count);
}
