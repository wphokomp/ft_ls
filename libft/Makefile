# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/01 15:15:18 by wphokomp          #+#    #+#              #
#    Updated: 2017/11/29 10:11:01 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_bzero_point.c ft_isalnum.c ft_isalpha.c\
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c\
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c\
	  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c\
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_chrcmp.c ft_strcpy.c\
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strlen_point.c ft_strmap.c\
	  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
	  ft_strnew.c ft_strnew_point.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
	  ft_strstr.c ft_strsub.c ft_strdup.c ft_strtrim.c ft_tolower.c\
	  ft_toupper.c ft_lstadd.c ft_str_chr.c ft_strjoin_nolim.c ft_mem_realloc.c

CFLAGS = -Wall\
		 -Werror\
		 -Wextra\
		 -std=c99

OBJ = *.o

INC = libft.h

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) -I $(INC) $(SRC)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
