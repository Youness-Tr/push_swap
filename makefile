# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 10:41:54 by ytarhoua          #+#    #+#              #
#    Updated: 2024/03/04 14:40:36 by ytarhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC  =  parsing.c utils_parsing.c op_tools.c swap.c ft_push.c ft_split.c rotation.c main.c
OBJ = $(SRC:.c=.o)
CC	= cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		${CC} $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)