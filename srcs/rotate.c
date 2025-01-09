/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:30:43 by caburges          #+#    #+#             */
/*   Updated: 2025/01/09 17:20:49 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_a(t_node **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_node **stack)
{
	rotate(stack);
	ft_putendl_fd("rb", 1);
}

void	rotate_ab(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
