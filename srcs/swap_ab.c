/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:41:58 by caburges          #+#    #+#             */
/*   Updated: 2024/12/20 19:11:42 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack *a, t_stack *b)
{
	int	temp;

	if (a != NULL && a->next != NULL)
	{
		temp = a->nb;
		a->nb = a->next->nb;
		a->next->nb = temp;
	}
	if (b != NULL && b->next != NULL)
	{
		temp = b->nb;
		b->nb = b->next->nb;
		b->next->nb = temp;
	}
	printf("ss\n");
}
