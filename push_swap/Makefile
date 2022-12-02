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
	   
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME) $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	make -C Libft clean
	rm -f $(OBJS)

fclean: clean
	make -C Libft fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
