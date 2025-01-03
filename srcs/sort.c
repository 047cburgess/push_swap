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

void	big_sort(t_node **a, t_node **b, int a_size)
{
	t_node	*min;
	t_node	*max;

	// Push first 2 into stack b
	push_b(a, b);
	push_b(a, b);
	set_min_max(&min, &max, *b);

	// Push to B in descending order until 3 remain in A
	while (a_size > 3)
	{

	print_stacks(*a, *b);
}
