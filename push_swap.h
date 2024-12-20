/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:43:16 by caburges          #+#    #+#             */
/*   Updated: 2024/12/20 20:25:23 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct t_stack
{
	int	nb;
	struct t_stack	*next;
}	t_stack;

t_stack	*new_node(int nb);
void	add_front(t_stack **head, t_stack *new);
void	clear_stack(t_stack **stack);
void	last_node(t_stack *stack);

// Operations
void	swap_a(t_stack *node);
void	swap_b(t_stack *node);
void	swap_ab(t_stack *a, t_stack *b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);

#endif
