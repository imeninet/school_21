# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harticho <harticho@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 16:21:48 by harticho          #+#    #+#              #
#    Updated: 2020/08/23 16:21:54 by harticho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_functions.c ft_write_cs.c ft_write_du.c ft_write_p.c ft_write_x.c

OBJ = $(SRC:.c=.o)

INCLUDEDIR = ./

LIBFTDIR = ./libft/

LIBFT = $(LIBFTDIR)libft.a

HEADERS = $(INCLUDEDIR)ft_printf.h

FLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c $(HEADERS) $(LIBFT)
	gcc $(FLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)
	cp $(LIBFT) ./$(NAME)

clean:
	make clean -C $(LIBFTDIR)
	/bin/rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	/bin/rm -f $(NAME)

re: fclean all
