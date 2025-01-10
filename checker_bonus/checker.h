/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caburges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:06 by caburges          #+#    #+#             */
/*   Updated: 2025/01/10 17:11:33 by caburges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "libft.h"

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	sa(t_node *node);
void	sb(t_node *node);
void	ss(t_node *a, t_node *b);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **a, t_node **b);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **a, t_node **b);

#endif
