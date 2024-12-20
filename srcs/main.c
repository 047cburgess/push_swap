/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:18:49 by caburges          #+#    #+#             */
/*   Updated: 2024/12/20 20:02:26 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initial_errors_found(int ac);
void	build_stack(t_stack **stack, char **av, int ac);
void	print_stacks(t_stack *a, t_stack *b); // to delete
void	run_test(t_stack *a, t_stack *b)
{
	print_stacks(a, b);
	swap_ab(a, b);
	print_stacks(a, b);	
	push_b(&a, &b);
	print_stacks(a, b);	
	push_a(&a, &b);
	print_stacks(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (initial_errors_found(ac)) // to complete function later
	{
		printf("Error\n"); // to amend to my pf
		return (1);
	}

	build_stack(&stack_a, av, ac);
	stack_b = NULL;
	if (stack_a == NULL)
	{
		printf("Error\n"); // to amend to my pf
		return (1);
	}
	run_test(stack_a, stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}

int	initial_errors_found(int ac)
{
	// NO NUMBERS GIVEN: Dont display anything
	if (ac == 1)
		return (1);
	// DUPLICATE NUMBERS
	// INVALID NUMBERS: 1) not in int; 2) not a number
	return (0);
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

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("a: ");
	while (a != NULL)
	{
		printf("%i, ", a->nb);
		a = a->next;
	}
	printf("\n");

	printf("b: ");
	while (b != NULL)
	{
		printf("%i, ", b->nb);
		b = b->next;
	}
	printf("\n\n");
}
