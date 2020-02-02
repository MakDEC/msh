# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 21:35:59 by aanger            #+#    #+#              #
#    Updated: 2018/10/25 23:27:49 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE = srcs/ft_atoi.c\
	   srcs/ft_bzero.c\
	   srcs/ft_convbi.c\
	   srcs/ft_convib.c\
	   srcs/ft_isalnum.c\
	   srcs/ft_isalpha.c\
	   srcs/ft_isascii.c\
	   srcs/ft_isdigit.c\
	   srcs/ft_islower.c\
	   srcs/ft_isprint.c\
	   srcs/ft_isupper.c\
	   srcs/ft_itoa.c\
	   srcs/ft_nbrlen.c\
	   srcs/ft_nbrlens.c\
	   srcs/ft_putchar.c\
	   srcs/ft_putchar_fd.c\
	   srcs/ft_putendl.c\
	   srcs/ft_putendl_fd.c\
	   srcs/ft_putnbr.c\
	   srcs/ft_putnbr_fd.c\
	   srcs/ft_putstr.c\
	   srcs/ft_putstr_fd.c\
	   srcs/ft_strcat.c\
	   srcs/ft_strchr.c\
	   srcs/ft_strclr.c\
	   srcs/ft_strcmp.c\
	   srcs/ft_strcpy.c\
	   srcs/ft_strdup.c\
	   srcs/ft_strjoin.c\
	   srcs/ft_strlen.c\
	   srcs/ft_strnew.c\
	   srcs/ft_strrchr.c\
	   srcs/ft_strsplit.c\
	   srcs/ft_strstr.c\
	   srcs/ft_strsub.c\
	   srcs/ft_strtrim.c\
	   srcs/ft_tolower.c\
	   srcs/ft_toupper.c\
	   srcs/ft_twopow.c\
	   srcs/get_next_line.c

CFLAGS = -Wall -Werror -Wextra
CC = gcc
OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))

objs/%.o: srcs/%.c
		@mkdir -p objs
		@$(CC) -c $< $(FLAGS) -o $@ -I ../includes
		@printf '\033[33;01m%s\n\033[0m' 'Transformation de $< en objet'

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@printf '\033[33;01m%s\n\033[0m' 'Archivage des objets'
		@ranlib $(NAME)
		@printf '\033[33;01m%s\n\033[0m' 'Indexation de la lib'

clean:
		@rm -rf objs
		@printf '\033[31;01m%s\n\033[0m' 'Suppression des objets de la libft'

fclean: clean
		@rm -rf $(NAME)
		@printf '\033[31;01m%s\n\033[0m' 'Suppression de $(NAME)'

re: fclean all

.PHONY: all clean fclean re
