/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:07:05 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/25 20:10:28 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*copie;

	last_node = ft_last_stack(*stack);
	last_node->next = *stack;
	last_node->previous->next = NULL;
	last_node->previous = NULL;
	last_node->index = -1;
	(*stack)->previous = last_node;
	*stack = last_node;
	copie = *stack;
	while (copie)
	{
		copie->index += 1;
		copie = copie->next;
	}
}

void	ft_rra(t_stack **stack, t_info *info)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_reverse_rotate(stack);
	ft_add_flag_median_all_a(stack, info);
	ft_find_place_in_stack(stack, info, 1);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack, t_info *info)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_reverse_rotate(stack);
	ft_add_flag_median_all_b(stack, info);
	ft_find_place_in_stack(stack, info, 0);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, t_info *info)
{
	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	ft_reverse_rotate(a);
	ft_add_flag_median_all_a(a, info);
	ft_find_place_in_stack(a, info, 1);
	ft_reverse_rotate(b);
	ft_add_flag_median_all_b(b, info);
	ft_find_place_in_stack(b, info, 0);
	write(1, "rrr\n", 4);
}
