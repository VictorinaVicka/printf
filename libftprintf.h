/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:31:27 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/08 16:55:42 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef	struct s_parsing
{
	int	zero;
	int	minus;
	int	width;
	int	dot;
	int	precision;
	char	specifier;
}			t_parsing;

int	ft_printf(const char *str, ...);
int ft_printchar(char c, t_parsing flag);
#endif
