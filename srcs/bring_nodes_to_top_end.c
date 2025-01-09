/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_nodes_to_top_end.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:43:31 by caburges          #+#    #+#             */
/*   Updated: 2025/01/09 17:44:30 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node *node, t_node **a, t_node **b)
{
	int	a_size;
	int	b_size;
	int	i;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	i = 0;
	while (i < node->index && i < node->target->index)
	{
		rotate_ab(a, b);
		i++;
	}
	while (*b != node)
		rotate_b(b);
	while (*a != node->target)
		rotate_a(a);
}

static void	rev_rotate_both(t_node *node, t_node **a, t_node **b)
{
	int	a_size;
	int	b_size;
	int	i;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	i = 0;
	while ((i < b_size - node->index) && (i < a_size - node->target->index))
	{
		rev_rotate_ab(a, b);
		i++;
	}
	while (*b != node)
		rev_rotate_b(b);
	while (*a != node->target)
		rev_rotate_a(a);
}

void	bring_right_nodes_to_top_end(t_node *node, t_node **a, t_node **b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	if (above_med(node->index, b_size)
		&& above_med(node->target->index, a_size))
		rotate_both(node, a, b);
	else if (!above_med(node->index, b_size)
		&& !above_med(node->target->index, a_size))
		rev_rotate_both(node, a, b);
	else if (above_med(node->index, b_size))
	{
		while (*b != node)
			rotate_b(b);
		while (*a != node->target)
			rev_rotate_a(a);
	}
	else
	{
		while (*b != node)
			rev_rotate_b(b);
		while (*a != node->target)
			rotate_a(a);
	}
}
