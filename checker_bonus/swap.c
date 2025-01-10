/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:41:58 by caburges          #+#    #+#             */
/*   Updated: 2025/01/10 17:00:42 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_node *node)
{
	int	temp;

	if (node != NULL && node->next != NULL)
	{
		temp = node->nb;
		node->nb = node->next->nb;
		node->next->nb = temp;
	}
}

void	sa(t_node *node)
{
	swap(node);
}

void	sb(t_node *node)
{
	swap(node);
}

void	ss(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
}
