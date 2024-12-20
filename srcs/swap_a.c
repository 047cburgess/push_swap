/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:41:58 by caburges          #+#    #+#             */
/*   Updated: 2024/12/20 19:01:15 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *node)
{
	int	temp;

	if (node != NULL && node->next != NULL)
	{
		temp = node->nb;
		node->nb = node->next->nb;
		node->next->nb = temp;
	}
	printf("sa\n");
}
