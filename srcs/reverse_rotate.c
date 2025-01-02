/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:02:16 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 12:36:07 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*old_head;
	t_stack	*end;

	if (stack_size(*head) > 1)
	{
		old_head = *head;
		end = last_node(*head);
		old_head->prev = end;
		end->next = *head;
		end->prev->next = NULL;
		(*head)->prev = end;
		*head = end;
		(*head)->prev = NULL;
	}
}

void	rev_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rev_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void	rev_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
