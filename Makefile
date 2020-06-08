# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfarenga <tfarenga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/29 15:18:22 by tfarenga          #+#    #+#              #
#    Updated: 2020/05/29 15:24:24 by tfarenga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CLANG = clang

FLAG = -Wall -Wextra -Werror

SRC =

OBJ = $(SRC:.c=.o)

all: $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c libft.h
	$(CLANG) $(FLAG) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all