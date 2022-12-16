CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

NAME = pipex
BONUS = pipex_bonus
LIBFT = libft.a

INC_DIR 	= includes
SRC_DIR		= srcs
LIBFT_DIR	= libft

SRCS = cmd_parser.c \
	   fork_exec.c\
	   ft_perror_exit.c\
	   ft_syscalls.c\
	   init_info.c\
	   pipex.c\
	   cmd_parser.c\
	   fork_exec.c\
	   ft_perror_exit.c\
	   ft_syscalls.c\
	   init_info.c\
	   pipex.c

SRCS_BONUS = srcs_bonus/checker_bonus.c \
			 srcs/data_structure/deque_get_data.c	\
			 srcs/data_structure/deque_op.c	\
			 srcs/data_structure/free_alloc.c \
			 srcs/data_structure/init.c \
			 \
			 srcs/operations/push.c	\
			 srcs/operations/reverse_rotate.c	\
			 srcs/operations/rotate.c	\
			 srcs/operations/swap.c	\
			 \
			 srcs/parser/parser.c \
			 srcs/parser/parser_utils.c	\
			 \
			 srcs/sort/sort_utils.c	\

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@

$(BONUS): $(OBJS_BONUS) 
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@

all: $(NAME) $(BONUS)

bonus: $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	make -C Libft clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C Libft fclean
	rm -f $(NAME) $(BONUS)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
