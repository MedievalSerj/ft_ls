#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sladonia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 15:36:56 by sladonia          #+#    #+#              #
#    Updated: 2017/02/07 15:37:02 by sladonia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
SRC = ft_ls.c ft_inspect_file.c \
				proc_input.c \
				ft_list_dir.c \
				list_functions.c \
				buble_sort.c \
				print_f.c \
				print_f_dir.c \
				initial_sort.c \
				sort_string.c \
				get_width.c \
				get_info.c \
				proc_links.c \
				proc_flags.c 
LIB_FT = libft.a
LIB_PRINTF = libftprintf.a
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror
all:    $(NAME)
$(NAME): $(OBJ)
	make -C ./libft
	make -C ./libftprintf
	gcc $(OBJ) -o $(NAME) libft/$(LIB_FT) libftprintf/$(LIB_PRINTF)
%.o: %.c
	gcc -c $(FLG) -o $@ $<
cleanlib:
	make clean -C ./libft
	make clean -C ./libftprintf 
fcleanlib:
	make fclean -C ./libft
	make fclean -C ./libftprintf 
clean: cleanlib
	rm -f $(OBJ)
fclean: clean fcleanlib
	rm -f $(NAME)
re: fclean all

