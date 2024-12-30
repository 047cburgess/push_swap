/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:18:49 by caburges          #+#    #+#             */
/*   Updated: 2024/12/30 17:51:59 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(t_stack **stack, char **av, int ac);
void	print_stacks(t_stack *a, t_stack *b);
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
	is_sorted(a) ? printf("a sorted\n") : printf("a not sorted\n");
	is_sorted(b) ? printf("b sorted\n") : printf("b not sorted\n");
	printf("Stack size a: %i\n", stack_size(a));
	printf("Stack size b: %i\n", stack_size(b));
	rotate_a(&a);
	print_stacks(a, b);	
	rotate_b(&b);
	print_stacks(a, b);	
	rotate_ab(&a, &b);
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
	
		

	run_test(stack_a, stack_b);
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
