/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:41:58 by caburges          #+#    #+#             */
/*   Updated: 2024/12/30 17:21:01 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *node)
{
	int	temp;

	if (node != NULL && node->next != NULL)
	{
		temp = node->nb;
		node->nb = node->next->nb;
		node->next->nb = temp;
	}
}

void	swap_a(t_stack *node)
{
	swap(node);
	printf("sa\n");
}

void	swap_b(t_stack *node)
{
	swap(node);
	printf("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
