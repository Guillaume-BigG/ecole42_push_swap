/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:04 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 16:31:39 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_swap_top_bonus(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	first_node->previous = second_node;
	if (first_node->next)
		first_node->next->previous = first_node;
	second_node->next = first_node;
	second_node->previous = NULL;
	*stack = second_node;
}

void	ft_sa_bonus(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_swap_top_bonus(stack);
}

void	ft_sb_bonus(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_swap_top_bonus(stack);
}

void	ft_ss_bonus(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	ft_swap_top_bonus(a);
	ft_swap_top_bonus(b);
}
