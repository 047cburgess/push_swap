/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:35:57 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 16:16:42 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **head)
{
	int	n_1;
	int	n_2;
	int	n_3;

	n_1 = (*head)->nb;
	n_2 = (*head)->next->nb;
	n_3 = (*head)->next->next->nb;
	if (n_1 > n_2 && n_2 < n_3 && n_1 < n_3)
		swap_a(*head);
	else if (n_1 > n_2 && n_2 > n_3)
	{
		swap_a(*head);
		rev_rotate_a(head);
	}
	else if (n_1 > n_2 && n_2 < n_3 && n_1 > n_3)
		rotate_a(head);
	else if (n_1 < n_2 && n_2 > n_3 && n_1 < n_3)
	{
		swap_a(*head);
		rotate_a(head);
	}
	else if (n_1 < n_2 && n_2 > n_3 && n_1 > n_3)
		rev_rotate_a(head);
}

void	push_cheapest_to_b(t_node **a, t_node **b)
{	
	t_node	*cheapest;
	t_node	*a_trav;
	int	a_size = stack_size(*a);
	int	b_size = stack_size(*b);

	map_current_index(*a, *b);
	assign_target_nodes(*a, *b);
	a_trav = *a;
	cheapest = *a;
	while (a_trav != NULL)
	{
		calculate_push_cost(a_trav, a_size, b_size);
		if (a_trav->push_cost == 0)
		{
			push_b(a, b);
			return ;
		}
		if (a_trav->push_cost < cheapest->push_cost)
			cheapest = a_trav;
		a_trav = a_trav->next;
	}
	bring_right_nodes_to_top(cheapest, a, b, a_size, b_size);
	push_b(a, b);
}
		
void	push_cheapest_to_a(t_node **a, t_node **b)
{	
	t_node	*cheapest;
	t_node	*b_trav;
	int	a_size = stack_size(*a);
	int	b_size = stack_size(*b);

	map_current_index(*a, *b);
	assign_target_nodes_end(*a, *b);
	b_trav = *b;
	cheapest = *b;
	while (b_trav != NULL)
	{
		calculate_push_cost(b_trav, b_size, a_size);
		if (b_trav->push_cost == 0)
		{
			push_a(a, b);
			return ;
		}
		if (b_trav->push_cost < cheapest->push_cost)
			cheapest = b_trav;
		b_trav = b_trav->next;
	}
	bring_right_nodes_to_top(cheapest, b, a, b_size, a_size);
	push_a(a, b);
}


void	big_sort(t_node **a, t_node **b, int a_size)
{
	int	total_nums;

	total_nums = a_size;
	push_b(a, b);
	a_size--;
	if (a_size > 3)
	{
		push_b(a, b);
		a_size--;
	}
	while (a_size > 3)
	{
		push_cheapest_to_b(a, b);
		a_size--;
	}
	sort_three(a);
	while (a_size < total_nums)
	{
		push_cheapest_to_a(a, b);
		a_size++;
	}
	bring_min_to_top(a, a_size);

}
