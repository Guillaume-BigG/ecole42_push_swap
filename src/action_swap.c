/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:04 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 16:31:33 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_top(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	first_node->index = second_node->index;
	first_node->previous = second_node;
	if (first_node->next)
		first_node->next->previous = first_node;
	second_node->next = first_node;
	second_node->index -= 1;
	second_node->previous = NULL;
	*stack = second_node;
}

void	ft_sa(t_stack **stack, t_info *info)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_swap_top(stack);
	ft_add_flag_median_all_a(stack, info);
	ft_find_place_in_stack(stack, info, 1);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack, t_info *info)
{
	if (!*stack || !(*stack)->next)
		return ;
	ft_swap_top(stack);
	ft_add_flag_median_all_b(stack, info);
	ft_find_place_in_stack(stack, info, 0);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, t_info *info)
{
	if (!*a || !(*a)->next)
		return ;
	if (!*b || !(*b)->next)
		return ;
	ft_swap_top(a);
	ft_add_flag_median_all_a(a, info);
	ft_find_place_in_stack(a, info, 1);
	ft_swap_top(b);
	ft_add_flag_median_all_b(b, info);
	ft_find_place_in_stack(b, info, 0);
	write(1, "ss\n", 3);
}
