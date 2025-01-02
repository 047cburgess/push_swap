/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:49 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 11:50:31 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack *new_dest_head;

	if (*src != NULL)
	{
		new_dest_head = *src;
		*src = (*src)->next;
		if (*src != NULL)
			(*src)->prev = NULL;
		if (*dest != NULL)
			(*dest)->prev = new_dest_head;
		new_dest_head->next = *dest;
		*dest = new_dest_head;
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	push(b, a);
	printf("pb\n");
}
