/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:19:23 by caburges          #+#    #+#             */
/*   Updated: 2025/01/02 15:54:07 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_max(t_stack **min, t_stack **max, t_stack *head)
{
	if (head->nb > head->next->nb)
	{
		*min = head->next;
		*max = head;
	}
	else
	{
		*min = head;
		*max = head->next;
	}
}
