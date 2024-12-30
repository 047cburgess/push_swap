/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:49 by caburges          #+#    #+#             */
/*   Updated: 2024/12/30 17:29:39 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack *temp;

	if (*src != NULL)
	{
		temp = (*src)->next;
		(*src)->next = *dest;
		*dest = *src;
		*src = temp;
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
