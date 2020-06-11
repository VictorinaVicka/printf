# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/29 15:18:22 by tfarenga          #+#    #+#              #
#    Updated: 2020/06/11 16:57:14 by tfarenga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CLANG = clang

FLAG = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isdigit.c ft_itoa_u_x.c ft_other.c ft_print_init.c ft_printf.c \
ft_printnumber.c ft_printp.c ft_printstr.c ft_strdup.c ft_toupper.c ft_itoa_p.c \
ft_strlen.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CLANG) $(FLAG) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all