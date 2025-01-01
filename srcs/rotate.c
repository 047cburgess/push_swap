/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:30:43 by caburges          #+#    #+#             */
/*   Updated: 2024/12/30 17:51:04 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*end;

	if (stack_size(*stack) > 1)
	{
		old_head = *stack;
		end = last_node(*stack);
		*stack = (*stack)->next;
		end->next = old_head;
		old_head->next = NULL;
	}
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	printf("ra\n");
}


void	rotate_b(t_stack **stack)
{
	rotate(stack);
	printf("rb\n");
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
