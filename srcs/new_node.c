/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:24:07 by caburges          #+#    #+#             */
/*   Updated: 2024/12/20 15:30:15 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}
