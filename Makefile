# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 23:29:24 by hvasylie          #+#    #+#              #
#    Updated: 2019/08/07 23:42:37 by hvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS=src/*.c

OBJECTS=*.o

INCLUDES=libft/libft.a

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
