# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:41:09 by malaamir          #+#    #+#              #
#    Updated: 2025/01/12 13:19:12 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------Source Files-----------------------------------#
SO_LONG_SRC = mand/so_long.c mand/destroy.c mand/get_next_line.c mand/get_next_line_utils.c \
	mand/key_hooks.c mand/parsing_map.c mand/render_map.c mand/ft_printf.c mand/ft_putchar_printf.c \
	mand/ft_putstr_printf.c mand/ft_putnbr_printf.c  mand/ft_strcmp.c  mand/init_game.c mand/check_path.c \
	mand/read_map.c

SO_LONG_BONUS_SRC = bonus/check_path_bonus.c bonus/destroy_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
	bonus/init_game_bonus.c bonus/key_hooks_bonus.c bonus/parsing_map_bonus.c bonus/render_map_bonus.c bonus/so_long_bonus.c \
	bonus/ft_printf_bonus.c bonus/ft_putchar_printf_bonus.c bonus/ft_putstr_printf_bonus.c bonus/ft_putnbr_printf_bonus.c \
	bonus/ft_strcmp_bonus.c bonus/read_map_bonus.c bonus/ft_itoa_bonus.c bonus/display_movements_bonus.c\

#-------------------------------Object Files-----------------------------------#
SO_LONG_OBJ = $(SO_LONG_SRC:.c=.o)

SO_LONG_BONUS_OBJ = $(SO_LONG_BONUS_SRC:.c=.o)

#-------------------------------Compiler and flags-----------------------------#
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -Imlx

#---------------------------Includes and Excutables----------------------------#
INCLUDES = mand/so_long.h
BONUS_INCLUDES = bonus/so_long_bonus.h
MANDATORY_NAME = so_long
BONUS_NAME = so_long_bonus

#---------------------------------Rules----------------------------------------#
all: $(MANDATORY_NAME)

bonus : $(BONUS_NAME)

$(MANDATORY_NAME): $(SO_LONG_OBJ)
	$(CC) $(FLAGS) $(SO_LONG_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(MANDATORY_NAME)


$(BONUS_NAME): $(SO_LONG_BONUS_OBJ)
	$(CC) $(FLAGS) $(SO_LONG_BONUS_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)

mand/%.o: mand/%.c $(INCLUDES)
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
