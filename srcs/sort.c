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
	int	nums[3];

	nums[0] = (*head)->nb;
	nums[1] = (*head)->next->nb;
	nums[2] = (*head)->next->next->nb;
	if (nums[0] < nums[1] && nums[0] < nums[2])
	{
		swap_a(*head);
		rotate_a(head);
	}
	else if (nums[0] > nums[1] && nums[1] > nums[2])
	{
		swap_a(*head);
		rev_rotate_a(head);
	}
	else if (nums[0] > nums[1] && nums[0] < nums[2])
		swap_a(*head);
	else if (nums[0] > nums[1] && nums[0] > nums[2])
		rotate_a(head);
	else
		rev_rotate_a(head);
}

void	push_cheapest_to_b(t_node **a, t_node **b, t_node **min, t_node **max)
{	
	t_node	*cheapest;
	t_node	*a_trav;
	int	a_size = stack_size(*a);
	int	b_size = stack_size(*b);

	map_current_index(*a, *b);
	assign_target_nodes(*a, *b, min, max);
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
	execute_push(cheapest, a, b, a_size, b_size);
	push_b(a, b);
}
		
void	push_cheapest_to_a(t_node **a, t_node **b, t_node **min, t_node **max)
{	
	t_node	*cheapest;
	t_node	*b_trav;
	int	a_size = stack_size(*a);
	int	b_size = stack_size(*b);

	map_current_index(*a, *b);
	assign_target_nodes(*b, *a, min, max);
	b_trav = *b;
	cheapest = *b;
	while (b_trav != NULL)
	{
		calculate_push_cost(b_trav, a_size, b_size);
		if (b_trav->push_cost == 0)
		{
			push_b(a, b);
			return ;
		}
		if (b_trav->push_cost < cheapest->push_cost)
			cheapest = b_trav;
		b_trav = b_trav->next;
	}
	execute_push(cheapest, a, b, a_size, b_size);
	push_a(a, b);
}


void	big_sort(t_node **a, t_node **b, int a_size)
{
	int	total_nums;

	total_nums = a_size;
	//
	// Push first 2 into stack b
	push_b(a, b);
	push_b(a, b);
	a_size = a_size - 2;

	// Push to B in descending order until 3 remain in A
	while (a_size > 3)
	{
		push_cheapest_to_b(a, b);
		a_size--;
	}

	// Sort the last three in A
	sort_three(a);

	// Push back to A in the right place
	while (a_size < total_nums)
	{
		push_cheapest_to_a(a, b);
		a_size++;
	}

	// Testing only: Print out the stacks at the end
	print_stacks(*a, *b);
}
