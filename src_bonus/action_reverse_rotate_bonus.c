/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:07:05 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/25 20:11:02 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_reverse_rotate_bonus(t_stack **stack)
{
	t_stack	*last_node;

	last_node = ft_last_stack_bonus(*stack);
	last_node->next = *stack;
	last_node->previous->next = NULL;
	last_node->previous = NULL;
	(*stack)->previous = last_node;
	*stack = last_node;
}

void	ft_rra_bonus(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_reverse_rotate_bonus(stack);
}

void	ft_rrb_bonus(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_reverse_rotate_bonus(stack);
}

void	ft_rrr_bonus(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	ft_reverse_rotate_bonus(a);
	ft_reverse_rotate_bonus(b);
}
