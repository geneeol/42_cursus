CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME	= pipex
BONUS	= pipex_bonus
LIBFT	= libft.a

INC_DIR 		= includes
SRC_DIR			= srcs
SRCS_BONUS_DIR	= srcs_bonus
LIBFT_DIR		= libft

SRCS = cmd_parser.c \
	   fork_exec.c\
	   ft_perror_exit.c\
	   ft_syscalls.c\
	   init_info.c\
	   pipex.c\

SRCS_BONUS = cmd_parser_bonus.c\
			 fork_exec_bonus.c\
			 ft_perror_exit_bonus.c \
			 ft_syscalls_bonus.c\
			 init_info_bonus.c\
			 pipex_bonus.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, $(SRCS_BONUS:.c=.o))

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@

$(BONUS): $(OBJS_BONUS) 
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@

all: $(NAME)

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
