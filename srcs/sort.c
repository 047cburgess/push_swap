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

void	sort_three(t_stack **head)
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

void	big_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*max;

	// Push first 2 into stack b
	push_b(a, b);
	push_b(a, b);
	set_min_max(&min, &max, *b);
	if ((*b)->nb < (*b)->next->nb)
		swap_b(*b);

	// Push to B in descending order until 3 remain in A
	while (stack_size(*a) > 3)
	{
		// if it's the new max or min, push it and make sure max on top
		if ((*a)->nb > max->nb || (*a)->nb < min->nb)
		{
			push_b(a, b);
			if ((*b)->nb < max->nb)
			{
				rotate_b(b);
				min = *b;
			}
			else
				max = *b;
		}
		else
		{
			while ((*b)->nb > (*a)->nb)
			{
				rotate_b(b);
			}
			push_b(a, b);
			while ((*b) != max)
				rotate_b(b);
		}
	}
	// Push back to A in the right place
	sort_three(a);

	print_stacks(*a, *b);
}
