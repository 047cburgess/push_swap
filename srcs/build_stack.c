#include "push_swap.h"

void	build_stack(t_node **stack, char **av, int ac)
{
	t_node	*node;
	long	nb;

	while (ac > 1)
	{
		nb = ft_atol(av[ac - 1]);
		if (not_valid(nb, av[ac - 1] || duplicate_found(*stack, (int)nb)
			ft_exit(stack);
		node = new_node((int)nb);
		if (!node)
			ft_exit(stack);
		add_front(stack, node);
		ac--;
	}
}
