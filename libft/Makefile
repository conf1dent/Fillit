# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 18:09:22 by bbekmama          #+#    #+#              #
#    Updated: 2019/05/25 22:13:03 by bbekmama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=*.c

OBJECTS=*.o

INCLUDES=./

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
		ar -rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
		/bin/rm -f *.o

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all
