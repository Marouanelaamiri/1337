# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:39:02 by malaamir          #+#    #+#              #
#    Updated: 2024/11/18 18:15:02 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar_printf.c ft_putstr_printf.c ft_putnbr_printf.c ft_unsigned_printf.c ft_putaddress_printf.c \
	 ft_puthexa_printf.c
	 

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

AR	= ar rc

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(BONUS_OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all