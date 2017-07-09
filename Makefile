# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/09 14:24:15 by wphokomp          #+#    #+#              #
#    Updated: 2017/07/09 16:15:50 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_ls.c list.c sort.c

FLAGS = clang -Wall -Werror -Wextra -g -I includes -o

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean && make -C libft/ all
	@$(FLAGS) $(NAME) $(SRC) libft/libft.a
	@rm -fr ft_ls.d*

clean:
	@make -C libft/ fclean

fclean:
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
