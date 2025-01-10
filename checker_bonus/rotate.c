/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:30:43 by caburges          #+#    #+#             */
/*   Updated: 2025/01/10 17:03:45 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_node **stack)
{
	t_node	*old_head;
	t_node	*end;

	if (stack_size(*stack) > 1)
	{
		old_head = *stack;
		end = last_node(*stack);
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		old_head->prev = end;
		end->next = old_head;
		old_head->next = NULL;
	}
}

void	ra(t_node **stack)
{
	rotate(stack);
}

void	rb(t_node **stack)
{
	rotate(stack);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
