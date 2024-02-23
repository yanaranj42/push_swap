NAME = push_swap

CC = cc -g 
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = arg_checker.c libft_utils.c movements.c push_swap.c sort_stack.c \
	   sort_utils.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@RM $(OBJS)

fclean: clean
	@RM $(NAME)

re: fclean all

.PHONY: all clean fclean re
