#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sladonia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 15:30:11 by sladonia          #+#    #+#              #
#    Updated: 2016/12/02 15:30:14 by sladonia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SRC =   ft_printf.c \
		ft_str_append.c \
		select.c \
		d_signed_decimal.c \
		ft_str_long.c \
		ft_str_append_unsafe.c \
		ft_char_n_str.c \
		definitions.c \
		validate_size.c \
		fill_struct.c \
		u_unsigned_decimal.c \
		ft_str_u_long.c \
		ft_str_hex.c \
		x_hex.c \
		o_octal.c \
		persent.c \
		c_char.c \
		wc_char.c \
		s_string.c \
		ws_string.c \
		p_hex.c \
		ft_atoi.c \
		ft_strnew.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_utf.c
OBJ = $(SRC:.c=.o)
HEADER = libftprintf.h
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
all: $(NAME)
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all