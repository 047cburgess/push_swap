/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:14:49 by caburges          #+#    #+#             */
/*   Updated: 2025/01/10 17:02:15 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	pa(t_node **a, t_node **b)
{
	push(a, b);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
}
