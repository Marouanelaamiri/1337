# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 19:39:42 by malaamir          #+#    #+#              #
#    Updated: 2025/01/22 18:52:34 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------Source Files------------------------------------#

SRC = helpers/ft_atoi.c helpers/ft_calloc.c helpers/ft_free.c helpers/ft_itoa.c helpers/ft_split.c helpers/ft_strcmp.c helpers/put_str.c\
	helpers/ft_strchr.c helpers/ft_strdup.c helpers/ft_strlen.c helpers/ft_substr.c helpers/ft_strjoin.c helpers/ft_memcpy.c  helpers/ft_atoi2.c\
	parsing_utils.c init_utils.c sort_stacks.c init_a_to_b.c init_b_to_a.c push_swap.c push.c rev_rotate.c rotate.c sort_stacks_utils.c sort_three.c initing_and_parsing.c stack_utils.c swap.c\
	
	

BONUS_SRC =

#------------------------------Object Files------------------------------------#
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)
#------------------------------Compiler and Flages------------------------------#
CC = cc

CFLAGS = -Wall -Wextra -Werror
#------------------------------Includes and Exuctables--------------------------#
NAME = push_swap

BONUS_NAME = checker

INCLUDES = push_swap.h

BONUS_INCLUDES = push_swap_bonus.h
#------------------------------Rules---------------------------------------------#
all: $(NAME)

bonus: $(BONUS_OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c $(INCLUDES) $(BONUS_INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@
#------------------------------Clean---------------------------------------------#
clean :
	rm -f $(OBJ) $(BONUS_OBJ)
	
fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
#------------------------------Rebuild--------------------------------------------#
re : fclean all