# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 00:03:36 by yaboukir          #+#    #+#              #
#    Updated: 2025/01/05 11:38:11 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SO_LONG = mand/so_long.c mand/game_rend.c mand/ft_keycodes.c \
	mand/ft_door.c mand/readingmap.c mand/fetch_pic.c \
	mand/ft_printf.c mand/ft_putchar.c mand/get_pic.c \
	mand/flood_fill.c mand/ft_putnbr.c mand/ft_split.c \
	mand/get_next_line.c mand/get_next_line_utils.c mand/ft_length.c \
	mand/moves.c mand/parsing.c mand/position.c mand/rendering.c \
	mand/wall_check.c mand/ft_putstr.c

SRCS_SO_LONG_BONUS = bonus/so_long_bonus.c bonus/game_rend_bonus.c \
	bonus/ft_keycodes_bonus.c bonus/ft_door_bonus.c \
	bonus/readingmap_bonus.c bonus/fetch_pic_bonus.c \
	bonus/ft_printf_bonus.c bonus/ft_putchar_bonus.c \
	bonus/get_pic_bonus.c bonus/flood_fill_bonus.c \
	bonus/ft_putnbr_bonus.c bonus/ft_split_bonus.c \
	bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
	bonus/ft_length_bonus.c bonus/moves_bonus.c \
	bonus/parsing_bonus.c bonus/position_bonus.c \
	bonus/rendering_bonus.c bonus/wall_check_bonus.c \
	bonus/ft_putstr_bonus.c bonus/get_enemy_pack.c \
	bonus/ft_itoa_bonus.c bonus/ft_get_frames.c

OBJS_SO_LONG = $(SRCS_SO_LONG:.c=.o)
OBJS_SO_LONG_BONUS = $(SRCS_SO_LONG_BONUS:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Imlx
INCLUDE = mand/so_long.h
INCLUDE_BONUS = bonus/so_long_bonus.h
NAME_SO_LONG = so_long
NAME_SO_LONG_BONUS = so_long_bonus

all: $(NAME_SO_LONG)

$(NAME_SO_LONG): $(OBJS_SO_LONG)
	$(CC) $(CFLAGS) $(OBJS_SO_LONG) -lmlx -framework OpenGL -framework AppKit -o $(NAME_SO_LONG)

bonus: $(NAME_SO_LONG_BONUS)

$(NAME_SO_LONG_BONUS): $(OBJS_SO_LONG_BONUS)
	$(CC) $(CFLAGS) $(OBJS_SO_LONG_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_SO_LONG_BONUS)

mand/%.o: mand/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SO_LONG) $(OBJS_SO_LONG_BONUS)

fclean: clean
	$(RM) $(NAME_SO_LONG) $(NAME_SO_LONG_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
