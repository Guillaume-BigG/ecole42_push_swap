/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:07 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/25 20:11:13 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_rotate_bonus(t_stack **stack)
{
	t_stack	*last_node;

	last_node = ft_last_stack_bonus(*stack);
	last_node->next = *stack;
	(*stack)->previous = last_node;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
	(*stack)->previous = NULL;
}

void	ft_ra_bonus(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_rotate_bonus(stack);
}

void	ft_rb_bonus(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_rotate_bonus(stack);
}

void	ft_rr_bonus(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	ft_rotate_bonus(a);
	ft_rotate_bonus(b);
}
