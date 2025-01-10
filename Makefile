NAME = push_swap
CHECKER_NAME = checker

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
	srcs/set_min_max.c \
	srcs/bring_nodes_to_top.c \
	srcs/bring_nodes_to_top_end.c \
	srcs/above_med.c

CHECKER_SRCS = checker_bonus/main.c \
	checker_bonus/get_next_line.c \
	checker_bonus/get_next_line_utils.c \
       	srcs/build_stack.c \
	srcs/manage_input_errors.c \
	srcs/is_sorted.c \
	srcs/new_node.c \
	srcs/add_front.c \
	srcs/clear_stack.c \
	srcs/last_node.c \
	srcs/stack_size.c
	checker_bonus/swap.c \
	checker_bonus/push.c \
	checker_bonus/rotate.c \
	checker_bonus/reverse_rotate.c 

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_DIR = libft
CHECKER_DIR = checker_bonus

CFLAGS = -g -I$(LIBFT_DIR) -I$(CHECKER_DIR) -I. -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(CHECKER_NAME): $(LIBFT) $(NAME) $(CHECKER_OBJS)
	cc $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER_NAME) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

bonus: $(CHECKER_NAME)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re all bonus
