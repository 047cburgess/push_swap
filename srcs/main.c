/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:18:49 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 15:48:58 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	b.head = NULL;
	if (ac == 1)
		return (1);
	build_stack(&a.head, av, ac);
	a.size = stack_size(a.head);
	if (!is_sorted(a.head))
	{
		if (a.size == 2)
			swap_a(a.head);
		else if (a.size == 3)
			sort_three(&a.head);
		else
			big_sort(&a.head, &b.head, a.size);
	}
	print_stacks(a.head, b.head);
	clear_stack(&a.head);
}
