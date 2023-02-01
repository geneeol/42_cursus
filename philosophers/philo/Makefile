CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = philo

INC_DIR = includes
SRC_DIR = srcs

SRCS = init.c \
	   main.c \
	   parse_input.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS): $(OBJS_BONUS) 
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

debug: CFLAGS += $(ACFLAGS) -g3


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all debug