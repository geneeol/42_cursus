CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INC_DIR = ./includes/

NAME = libft.a

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   				\
	   ft_strlen.c	\
	   ft_memset.c	\
	   ft_bzero.c	\
	   ft_memcpy.c	\
	   ft_memmove.c	\
	   ft_strlcpy.c	\
	   ft_strlcat.c	\
	  				\
	   ft_toupper.c \
	   ft_tolower.c \
	   				\
	   ft_strchr.c	\
	   ft_strrchr.c	\
	   ft_memcmp.c	\
	   ft_strnstr.c	\
	   ft_atoi.c	\

SRCS := $(addprefix $(SRC_DIR), $(SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@ 

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: clean fclean re all

#$(info $(SRCS))
