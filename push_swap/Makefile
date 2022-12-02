CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker 
LIBFT = libft.a

INC_DIR 	= includes
LIBFT_DIR	= libft

SRCS = push_swap.c \
	   \
	   data_structure/deque_get_data.c	\
	   data_structure/deque_op.c	\
	   data_structure/free_alloc.c \
	   data_structure/init.c \
	   \
	   operations/push.c	\
	   operations/reverse_rotate.c	\
	   operations/roate.c	\
	   operations/swap.c	\
	   \
	   parser/parser.c	\
	   parser/parser_utils.c	\
	   \
	   sort/sort_algorithm.c	\
	   sort/sort_big.c	\
	   sort/sort_exec_rotation.c	\
	   sort/sort_small.c	\
	   sort_utils.c	\
	   
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)

all: $(NAME) $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_DIR)/$(LIBFT)

$(NAME): $(OBJS)
	make -C libft

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
