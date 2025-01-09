/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:41:58 by caburges          #+#    #+#             */
/*   Updated: 2025/01/09 12:58:00 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap_a(t_node *node)
{
	swap(node);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_node *node)
{
	swap(node);
	ft_putendl_fd("sb", 1);
}

void	swap_ab(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
