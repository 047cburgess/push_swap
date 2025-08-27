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

void	set_min_max(t_node **min, t_node **max, t_node *head)
{
	*min = head;
	*max = head;
	while (head != NULL)
	{
		if (head->nb < (*min)->nb)
			*min = head;
		if (head->nb > (*max)->nb)
			*max = head;
		head = head->next;
	}
}
