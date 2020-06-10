/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:58:42 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/09 11:59:07 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *str)
{
	int		index;
	char	*dst;

	index = 0;
	while (str[index] != '\0')
		index++;
	dst = (char*)malloc(sizeof(char) * (index + 1));
	if (dst == NULL)
		return (NULL);
	index = 0;
	while (str[index] != '\0')
	{
		dst[index] = str[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
