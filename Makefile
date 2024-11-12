NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strncmp.c ft_substr.c \
      ft_bzero.c ft_isascii.c ft_memcmp.c ft_split.c ft_strlcat.c ft_strnstr.c ft_tolower.c \
      ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c \
      ft_isalnum.c ft_isprint.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_itoa.c \
	  ft_strmapi.c  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c 

OBJS = $(SRC:.c=.o)
AR	= ar rcs
FLAGS = -Wall -Wextra -Werror
CC = cc
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
