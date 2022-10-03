# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:23:03 by dahkang           #+#    #+#              #
#    Updated: 2022/10/03 19:32:44 by dahkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_printf_numeric.c \
	   ft_printf_str.c \
	   ft_printf_utils.c

OBJS = $(SRCS:c=o) 

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	make -C Libft
	cp ./Libft/libft.a $@
	ar rcs $@ $?

clean:
	make -C Libft clean
	rm -f $(OBJS)

fclean: clean
	make -C Libft fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re lib
