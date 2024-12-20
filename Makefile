NAME = push_swap

SRCS = srcs/main.c \
	srcs/new_node.c \
	srcs/add_front.c \
	srcs/clear_stack.c \
	srcs/swap_a.c \
	srcs/swap_b.c \
	srcs/swap_ab.c \
	srcs/push_a.c \
	srcs/push_b.c \
	srcs/rotate_a.c \
	srcs/rotate_b.c \
	srcs/rotate_ab.c \
	srcs/last_node.c

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
