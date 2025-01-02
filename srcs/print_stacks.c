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

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("a (%s) (stack size: %i)\n\t", is_sorted(a) ? "sorted" : "not sorted", stack_size(a));
	while (a != NULL)
	{
		printf("%i ", a->nb);
		if (a->prev != NULL)
			printf("(prev: %i), ", a->prev->nb);
		if (a->prev == NULL)
			printf("(prev: NULL), ");
		a = a->next;
	}
	printf("NULL");
	printf("\n");

	printf("b (%s) (stack size: %i)\n\t", is_sorted(b) ? "sorted" : "not sorted", stack_size(b));
	while (b != NULL)
	{
		printf("%i ", b->nb);
		if (b->prev != NULL)
			printf("(prev: %i), ", b->prev->nb);
		if (b->prev == NULL)
			printf("(prev: NULL), ");
		b = b->next;
	}
	printf("NULL");
	printf("\n\n");
}
