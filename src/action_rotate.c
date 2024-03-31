/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:19:07 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/14 19:53:52 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*copie;

	last_node = ft_last_stack(*stack);
	last_node->next = *stack;
	(*stack)->index = last_node->index + 1;
	(*stack)->previous = last_node;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
	(*stack)->previous = NULL;
	copie = *stack;
	while (copie)
	{
		copie->index -= 1;
		copie = copie->next;
	}
}

void	ft_ra(t_stack **stack, t_info *info)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_rotate(stack);
	ft_add_flag_median_all_a(stack, info);
	ft_find_place_in_stack(stack, info, 1);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack, t_info *info)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_rotate(stack);
	ft_add_flag_median_all_b(stack, info);
	ft_find_place_in_stack(stack, info, 0);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b, t_info *info)
{
	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	ft_rotate(a);
	ft_add_flag_median_all_a(a, info);
	ft_find_place_in_stack(a, info, 1);
	ft_rotate(b);
	ft_add_flag_median_all_b(b, info);
	ft_find_place_in_stack(b, info, 0);
	write(1, "rr\n", 3);
}
