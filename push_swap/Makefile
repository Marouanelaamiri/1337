# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 19:39:42 by malaamir          #+#    #+#              #
#    Updated: 2025/01/30 21:29:16 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------Source Files------------------------------------#

SRC = helpers/ft_atoi2.c  helpers/ft_split.c helpers/free_split.c \
	parsing_utils.c init_utils.c sort_stacks.c init_a_to_b.c init_b_to_a.c push_swap.c push.c rev_rotate.c \
	rotate.c sort_stacks_utils.c sort_three.c initing_and_parsing.c stack_utils.c swap.c \
 
#------------------------------Object Files------------------------------------#
OBJ = $(SRC:.c=.o)

#------------------------------Compiler and Flages------------------------------#
CC = cc

CFLAGS = -Wall -Wextra -Werror
#------------------------------Includes and Exuctables--------------------------#
NAME = push_swap

INCLUDES = push_swap.h

#------------------------------Rules---------------------------------------------#
all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@
#------------------------------Clean---------------------------------------------#
clean :
	rm -f $(OBJ) $(BONUS_OBJ)
	
fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
#------------------------------Rebuild--------------------------------------------#
re : fclean all