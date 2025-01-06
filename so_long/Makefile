# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 09:53:45 by malaamir          #+#    #+#              #
#    Updated: 2025/01/05 10:34:15 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG_SRC =  mandatory/so_long.c mandatory/game_rend.c mandatory/ft_keycodes.c \
	mandatory/ft_door.c mandatory/readingmap.c mandatory/fetch_pic.c \
	mandatory/ft_printf.c mandatory/ft_putchar_printf.c mandatory/get_pic.c \
	mandatory/flood_fill.c mandatory/ft_putnbr_printf.c mandatory/ft_split.c \
	mandatory/get_next_line.c mandatory/get_next_line_utils.c mandatory/ft_length.c \
	mandatory/moves.c mandatory/parsing.c mandatory/position.c mandatory/rendering.c \
	mandatory/wall_check.c mandatory/ft_putstr_printf.c mandatory/ft_calloc.c \
	mandatory/ft_substr.c 

SO_LONG_BONUS_SRC =

SO_LONG_OBJ = $(SO_LONG_SRC:.c=.o)

SO_LONG_BONUS_OBJ = $(SO_LONG_BONUS_SRC:.c=.o)

CC = CC
AR = ar r
RM = rm -f
FLAGS = -Wall -Wextra -Werror -Imlx
INCLUDES = mandatory/so_long.h
BONUS_INCLUDES = bonus/so_long_bonus.h
MANDATORY_NAME = so_long
BONUS_NAME = so_long_bonus

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(SO_LONG_OBJ)
	$(CC) $(FLAGS) $(SO_LONG_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(MANDATORY_NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(SO_LONG_BONUS_OBJ)
	$(CC) $(FLAGS) $(SO_LONG_BONUS_OBJ) -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)

mandatory/%.o: mandatory/%.c $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BONUS_INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(SO_LONG_OBJ) $(SO_LONG_BONUS_OBJ)

fclean: clean
	$(RM) $(MANDATORY_NAME) $(BONUS_NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus