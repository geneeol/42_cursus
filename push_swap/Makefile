CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker 
LIBFT = libft.a

INC_DIR 	= includes
SRC_DIR		= srcs
LIBFT_DIR	= libft

SRCS = push_swap.c	\
	   \
	   data_structure/deque_get_data.c	\
	   data_structure/deque_op.c	\
	   data_structure/free_alloc.c \
	   data_structure/init.c \
	   data_structure/print_operations.c	\
	   \
	   operations/push.c	\
	   operations/reverse_rotate.c	\
	   operations/rotate.c	\
	   operations/swap.c	\
	   \
	   parser/parser.c	\
	   parser/parser_utils.c	\
	   \
	   sort/sort_algorithm.c	\
	   sort/sort_big.c	\
	   sort/sort_exec_rotation.c	\
	   sort/sort_small.c	\
	   sort/sort_utils.c	\

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
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
