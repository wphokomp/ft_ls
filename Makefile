# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/09 14:24:15 by wphokomp          #+#    #+#              #
#    Updated: 2017/07/09 16:27:48 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_ls.c list.c sort.c

FLAGS = clang -Wall -Werror -Wextra -g -I includes -o

all: $(NAME)

$(NAME): $(SRC)
	@make -C lib/ fclean && make -C lib/ all
	@$(FLAGS) $(NAME) $(SRC) lib/libft.a
	@rm -fr ft_ls.d*

clean:
	@make -C lib/ fclean

fclean:
	@make -C lib/ fclean
	@rm -f $(NAME)

re: fclean all
