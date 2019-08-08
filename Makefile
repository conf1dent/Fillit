# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvasylie <hvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 23:29:24 by hvasylie          #+#    #+#              #
#    Updated: 2019/08/07 13:39:01 by hvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS=*.c

OBJECTS=*.o

INCLUDES=libft/

FLAGS=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc -g -o $(NAME) $(FLAGS) src/$(SRCS) $(INCLUDES)libft.a

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all