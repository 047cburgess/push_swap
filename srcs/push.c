/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:49 by caburges          #+#    #+#             */
/*   Updated: 2025/01/09 17:20:19 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*new_dest_head;

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

void	push_a(t_node **a, t_node **b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_node **a, t_node **b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
