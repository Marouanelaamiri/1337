# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaamir <malaamir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 20:07:27 by malaamir          #+#    #+#              #
#    Updated: 2025/02/04 12:52:34 by malaamir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus
SRCC = client.c utils1.c utils2.c
SRCS = server.c utils1.c utils2.c
SRCC_BONUS = client_bonus.c utils1.c utils2.c
SRCS_BONUS = server_bonus.c utils1.c utils2.c
 
#------------------------------Object Files------------------------------------#
OBJC = ${SRCC:%.c=%.o}
OBJS = ${SRCS:%.c=%.o}
OBJC_BONUS = ${SRCC_BONUS:%.c=%.o}
OBJS_BONUS = ${SRCS_BONUS:%.c=%.o}
#------------------------------Compiler and Flages------------------------------#
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
#------------------------------Includes and Exuctables--------------------------#
INCLUDE = minitalk.h
#------------------------------Rules---------------------------------------------#
all:	$(NAMEC) $(NAMES)

bonus: $(NAMEC_BONUS) $(NAMES_BONUS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAMEC): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAMEC)

$(NAMES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAMES)

$(NAMEC_BONUS) : $(OBJC_BONUS)
	$(CC) $(CFLAGS) $(OBJC_BONUS) -o $(NAMEC_BONUS)

$(NAMES_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAMES_BONUS)
#------------------------------Clean---------------------------------------------#
clean:
	$(RM) $(OBJC)
	$(RM) $(OBJS)
	$(RM) $(OBJC_BONUS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	$(RM) $(NAMEC_BONUS)
	$(RM) $(NAMES_BONUS)
#------------------------------Rebuild--------------------------------------------#
re : fclean all