# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 10:41:54 by ytarhoua          #+#    #+#              #
#    Updated: 2024/03/13 17:35:56 by ytarhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SRC  =  parsing.c parsing_tools.c tools.c swap.c push_rotate.c ft_split.c r_rotation.c main.c sorting.c algo.c
SRC_B =  parsing.c parsing_tools.c tools.c swap.c push_rotate.c ft_split.c r_rotation.c sorting.c algo.c
SRC_B += bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CC	= cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

all : $(NAME)

$(NAME) : $(OBJ)
		${CC} $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_B)
	${CC} $(CFLAGS) $(OBJ_B) -o $(BONUS)

clean :
		rm -rf $(OBJ) $(OBJ_B)

fclean : clean
		rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)