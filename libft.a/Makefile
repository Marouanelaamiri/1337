NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strncmp.c ft_substr.c \
      ft_bzero.c ft_isascii.c ft_memcmp.c ft_split.c ft_strlcat.c ft_strnstr.c ft_tolower.c \
      ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c \
      ft_isalnum.c ft_isprint.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_itoa.c \
	  ft_strmapi.c  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	 

OBJS = ft_atoi.o ft_isalpha.o ft_memchr.o ft_memset.o ft_strjoin.o ft_strncmp.o ft_substr.o \
	 ft_bzero.o ft_isascii.o ft_memcmp.o ft_split.o ft_strlcat.o ft_strnstr.o ft_tolower.o \
	 ft_calloc.o ft_isdigit.o ft_memcpy.o ft_strchr.o ft_strlcpy.o ft_strrchr.o ft_toupper.o \
	 ft_isalnum.o ft_isprint.o ft_memmove.o ft_strdup.o ft_strlen.o ft_strtrim.o ft_itoa.o \
	 ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	 
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

BONUS_OBJ = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o \
			ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o
CC = cc
FLAGS = -Wall -Wextra -Werror

AR	= ar rcs

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS) 

bonus: $(BONUS_OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	$(AR) $(NAME) $@
	

clean:
	rm -rf $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all