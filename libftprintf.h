/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:31:27 by tfarenga          #+#    #+#             */
/*   Updated: 2020/06/11 15:09:58 by tfarenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_parsing
{
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	char		specifier;
}				t_parsing;

int				ft_printf(const char *str, ...);
int				ft_atoi(const char *str);
int				ft_isdigit(int ch);
char			*ft_itoa_u_x(unsigned int n, int system, int defin);
int				ft_precision(const char **str, va_list argptr);
int				ft_width(const char **str, va_list argptr);
t_parsing		ft_flag_init(void);
int				ft_not_flag(char str);
int				ft_print_d_i(int num, t_parsing flag);
int				ft_print_u(unsigned int num, t_parsing flag);
int				ft_print_x(unsigned int num, t_parsing flag);
int				ft_printp(void *p, t_parsing flag);
int				ft_printchar(char c, t_parsing flag);
int				ft_printstr(char *str, t_parsing flag);
char			*ft_strdup(const char *str);
int				ft_toupper(int ch);

#endif
