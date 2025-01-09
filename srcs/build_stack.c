/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:16:28 by caburges          #+#    #+#             */
/*   Updated: 2025/01/09 17:16:30 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(t_node **stack, char **av, int ac)
{
	t_node	*node;
	long	nb;

	while (ac > 1)
	{
		nb = ft_atol(av[ac - 1]);
		if ((not_valid(nb, av[ac - 1]) || (duplicate_found(*stack, (int)nb))))
			ft_exit(stack);
		node = new_node((int)nb);
		if (!node)
			ft_exit(stack);
		add_front(stack, node);
		ac--;
	}
}
