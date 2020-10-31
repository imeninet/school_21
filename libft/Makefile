# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harticho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 11:29:24 by harticho          #+#    #+#              #
#    Updated: 2020/02/17 13:42:24 by harticho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strdup.c \
		ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_memset.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_memmove.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_strmapi.c \

OBJ = $(SRC:.c=.o)

HEADER_FILE = libft.h

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

%.o: %.c $(HEADER_FILE)
	gcc $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
