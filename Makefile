NAME = push_swap

SRCS = srcs/main.c \
       srcs/build_stack.c \
	srcs/manage_input_errors.c \
	srcs/is_sorted.c \
	srcs/new_node.c \
	srcs/add_front.c \
	srcs/clear_stack.c \
	srcs/swap.c \
	srcs/push.c \
	srcs/rotate.c \
	srcs/reverse_rotate.c \
	srcs/last_node.c \
	srcs/stack_size.c \
	srcs/sort.c \
	srcs/sort_utils.c \
	srcs/print_stacks.c \
	srcs/set_min_max.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

LIBFT_DIR = libft

CFLAGS = -g -I$(LIBFT_DIR) -I. -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re all
