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

void	build_stack(t_stack **stack, char **av, int ac);

void	run_test(t_stack *a, t_stack *b)
{
	print_stacks(a, b);
	swap_ab(a, b);
	print_stacks(a, b);	
	push_b(&a, &b);
	print_stacks(a, b);	
	push_b(&a, &b);
	print_stacks(a, b);	
	push_b(&a, &b);
	print_stacks(a, b);	
	push_a(&a, &b);
	print_stacks(a, b);
	rotate_a(&a);
	print_stacks(a, b);	
	rotate_b(&b);
	print_stacks(a, b);	
	rotate_ab(&a, &b);
	print_stacks(a, b);	
	rev_rotate_a(&a);
	print_stacks(a, b);	
	rev_rotate_b(&b);
	print_stacks(a, b);	
	rev_rotate_ab(&a, &b);
	print_stacks(a, b);	
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1) // No args given
		return (1);

	if (initial_errors_found(ac, av))
	{
		write(2, "Error\n", 6);
		return (2);
	}
	build_stack(&stack_a, av, ac);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (3);
	}
	int size = stack_size(stack_a);
	if (!is_sorted(stack_a))
	{
		if (size == 2)
			swap_a(stack_a);
		else if (size == 3)
			sort_three(&stack_a);
		else
			big_sort(&stack_a, &stack_b);
	}
	//run_test(stack_a, stack_b);
	is_sorted(stack_a) ? ft_putendl_fd("OK", 1) : ft_putendl_fd("Error", 1);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}

void	build_stack(t_stack **stack, char **av, int ac)
{
	t_stack	*node;
	*stack = NULL;

	while (ac > 1)
	{
		node = new_node(ft_atoi(av[ac - 1]));
		if (!node)
		{
			clear_stack(stack);
			return ;
		}
		add_front(stack, node);
		ac--;
	}
}

