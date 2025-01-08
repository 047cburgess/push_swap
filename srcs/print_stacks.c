/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:47:45 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 15:48:39 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node *a, t_node *b)
{
	printf("a (%s) (stack size: %i)\n\t", is_sorted(a) ? "sorted" : "not sorted", stack_size(a));
	while (a != NULL)
	{
		printf("%i ", a->nb);
		a = a->next;
	}
	printf("NULL");
	printf("\n");

	printf("b (%s) (stack size: %i)\n\t", is_sorted(b) ? "sorted" : "not sorted", stack_size(b));
	while (b != NULL)
	{
		printf("%i ", b->nb);
		b = b->next;
	}
	printf("NULL");
	printf("\n\n");
}
