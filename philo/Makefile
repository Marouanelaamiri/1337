# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 16:24:51 by malaamir          #+#    #+#              #
#    Updated: 2025/03/05 16:27:51 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------Source Files------------------------------------#
SRC = ft_atoi.c ft_strlen.c init_forks.c init_philo.c init_sim.c parsing.c \
		philo.c routine.c start_sim.c the_waiter.c utils.c
 
#------------------------------Object Files------------------------------------#
OBJ = $(SRC:.c=.o)
#------------------------------Compiler and Flages------------------------------#
CC = cc

CFLAGS = -Wall -Wextra -Werror
#------------------------------Includes and Exuctables--------------------------#
NAME = philo

#------------------------------Rules---------------------------------------------#
all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@
#------------------------------Clean---------------------------------------------#
clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)
#------------------------------Rebuild--------------------------------------------#
re : fclean all