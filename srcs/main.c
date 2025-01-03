/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:18:49 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 15:48:58 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	build_stack(&stack_a, av, ac);
	size = stack_size(stack_a);
	if (!is_sorted(stack_a))
	{
		if (size == 2)
			swap_a(stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else
			big_sort(&stack_a, &stack_b, size);
	}
	is_sorted(stack_a) ? ft_putendl_fd("OK", 1) : ft_putendl_fd("Error", 2);
	clear_stack(&stack_a);
}
