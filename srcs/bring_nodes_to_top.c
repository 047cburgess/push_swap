/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_nodes_to_top.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:43:31 by caburges          #+#    #+#             */
/*   Updated: 2025/01/18 13:16:08 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node *node, t_node **a, t_node **b)
{
	int	i;

	i = 0;
	while (i < node->index && i < node->target->index)
	{
		rotate_ab(a, b);
		i++;
	}
	while (*a != node)
		rotate_a(a);
	while (*b != node->target)
		rotate_b(b);
}

static void	rev_rotate_both(t_node *node, t_node **a, t_node **b)
{
	int	a_size;
	int	b_size;
	int	i;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	i = 0;
	while ((i < a_size - node->index) && (i < b_size - node->target->index))
	{
		rev_rotate_ab(a, b);
		i++;
	}
	while (*a != node)
		rev_rotate_a(a);
	while (*b != node->target)
		rev_rotate_b(b);
}

void	bring_nodes_to_top(t_node *node, t_node **a, t_node **b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	if (above_med(node->index, a_size) && above_med(node->target->index, b_size))
		rotate_both(node, a, b);
	else if (!above_med(node->index, a_size) && !above_med(node->target->index, b_size))
		rev_rotate_both(node, a, b);
	else if (above_med(node->index, a_size))
	{
		while (*a != node)
			rotate_a(a);
		while (*b != node->target)
			rev_rotate_b(b);
	}
	else
	{
		while (*a != node)
			rev_rotate_a(a);
		while (*b != node->target)
			rotate_b(b);
	}
}
