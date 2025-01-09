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
	t_node	*a;
	t_node	*b;
	int	a_size;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	build_stack(&a, av, ac);
	a_size = stack_size(a);
	if (!is_sorted(a))
	{
		if (a_size == 2)
			swap_a(a);
		else if (a_size == 3)
			sort_three(&a);
		else
			big_sort(&a, &b, a_size);
	}
	if (is_sorted(a))
		printf("OK\n");
	else
		printf("KO\n");

	clear_stack(&a);
}
