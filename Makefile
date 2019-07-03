#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 11:27:00 by vzhao             #+#    #+#              #
#    Updated: 2019/06/24 13:48:27 by vzhao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft
SRC = srcs
FILES = srcs/read.c \
		srcs/run.c \
		srcs/solve.c

all: $(NAME)
	
$(NAME):
	@Make -C $(LIB)
	@gcc -Wall -Wextra -Werror -I $(SRC) -I $(LIB) -L $(LIB) -lft -o $(NAME) $(FILES)
	
clean:
	@Make clean -C $(LIB)

fclean: clean
	@Make fclean -C $(LIB)
	@/bin/rm -f $(NAME)

re: fclean all
