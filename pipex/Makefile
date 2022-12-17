CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
BONUS = pipex
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

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

OBJS_BONUS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

#$(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@

#$(BONUS): $(OBJS) 
#	make all -C $(LIBFT_DIR)
#	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@

all: $(NAME)

bonus: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	make -C Libft clean
	rm -f $(OBJS)

fclean: clean
	make -C Libft fclean
	rm -f $(NAME) $(BONUS)

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
