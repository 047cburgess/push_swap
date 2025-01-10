/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:02:16 by caburges          #+#    #+#             */
/*   Updated: 2025/01/10 17:04:49 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*old_head;
	t_node	*end;

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

void	rra(t_node **stack)
{
	reverse_rotate(stack);
}

void	rrb(t_node **stack)
{
	reverse_rotate(stack);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
