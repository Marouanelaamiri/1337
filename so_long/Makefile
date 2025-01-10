# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:41:09 by malaamir          #+#    #+#              #
#    Updated: 2025/01/10 13:41:52 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------Source Files-----------------------------------#
SO_LONG_SRC = so_long.c destroy.c get_next_line.c get_next_line_utils.c \
	key_hooks.c parsing_map.c render_map.c ft_printf.c ft_putchar_printf.c \
	ft_putstr_printf.c ft_putnbr_printf.c  ft_strcmp.c  init_game.c check_path.c read_map.c\

SO_LONG_BONUS_SRC =

#-------------------------------Object Files-----------------------------------#
SO_LONG_OBJ = $(SO_LONG_SRC:.c=.o)

SO_LONG_BONUS_OBJ = $(SO_LONG_BONUS_SRC:.c=.o)

#-------------------------------Compiler and flags-----------------------------#
CC = cc
AR = ar
RM = rm -f
FLAGS = -Wall -Wextra -Werror -Imlx 

#---------------------------Includes and Excutables----------------------------#
INCLUDES = so_long.h
BONUS_INCLUDES = so_long_bonus.h
MANDATORY_NAME = so_long
BONUS_NAME = so_long_bonus

#---------------------------------Rules----------------------------------------#
all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(SO_LONG_OBJ)
	$(CC) $(FLAGS) $(SO_LONG_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(MANDATORY_NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(SO_LONG_BONUS_OBJ)
	$(CC) $(FLAGS) $(SO_LONG_BONUS_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BONUS_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@
	
#---------------------------------Cleaning-------------------------------------#
clean:
	$(RM) $(SO_LONG_OBJ) $(SO_LONG_BONUS_OBJ)

fclean: clean
	$(RM) $(MANDATORY_NAME) $(BONUS_NAME)
#---------------------------------Rebuilding------------------------------------#
re: fclean all

.PHONY: all clean fclean re bonus