# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/08 19:29:12 by wphokomp          #+#    #+#              #
#    Updated: 2017/11/29 10:12:19 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/empty.c\
	  src/lists.c\
	  src/print.c\
	  src/utils.c\
	  src/sort.c\
	  src/error_management.c\
	  src/get_content.c\
	  src/parse_args.c\
	  src/ft_stats.c\
	  src/ft_ls.c

FLAGS = clang -Wall -Werror -Wextra -g -I libft -o

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean && make -C libft/ all
	@$(FLAGS) $(NAME) $(SRC) libft/libft.a
	@rm -fr ft_ls.dSYM

clean:
	@make -C libft/ clean

fclean:
	@make -C libft/ fclean
	@rm -fr $(NAME)

re: fclean all
