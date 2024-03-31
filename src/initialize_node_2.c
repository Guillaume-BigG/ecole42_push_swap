/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_node_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:35:38 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 19:41:35 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_flag_median_all_a(t_stack **stack, t_info *info)
{
	t_stack	*copy;

	copy = *stack;
	while (copy)
	{
		if (copy->index > info->median_a)
			copy->flag_above_median = 1;
		else
			copy->flag_above_median = 0;
		copy = copy->next;
	}
}

void	ft_add_flag_median_all_b(t_stack **stack, t_info *info)
{
	t_stack	*copy;

	copy = *stack;
	while (copy)
	{
		if (copy->index > info->median_b)
			copy->flag_above_median = 1;
		else
			copy->flag_above_median = 0;
		copy = copy->next;
	}
}

void	ft_check_extreme(t_stack **stack, t_stack *copy, t_info *info, int flag)
{
	if (flag == 1)
	{
		if (copy->reworked_value > info->current_max_b)
			copy->asso_node = ft_find_max_list_address(stack);
		else if (copy->reworked_value < info->current_min_b)
			copy->asso_node = ft_find_max_list_address(stack);
	}
	else
	{
		if (copy->reworked_value > info->current_max_a)
			copy->asso_node = ft_find_min_list_address(stack);
		else if (copy->reworked_value < info->current_min_a)
			copy->asso_node = ft_find_min_list_address(stack);
	}
}

void	ft_find_asso_node_for_b(t_stack **b, t_stack **a, t_info *info,
		int flag)
{
	t_stack	*copy_a;
	t_stack	*copy_b;
	int		temp;

	copy_b = *b;
	while (copy_b)
	{
		copy_a = *a;
		ft_check_extreme(a, copy_b, info, flag);
		if (copy_b->reworked_value < info->current_max_a
			&& copy_b->reworked_value > info->current_min_a)
		{
			temp = ft_find_temp(a, copy_b, 0);
			find_node(copy_b, copy_a, temp, 0);
		}
		copy_b = copy_b->next;
	}
}

void	ft_find_place_in_stack(t_stack **stack, t_info *info, int flag)
{
	t_stack	*copy;

	copy = *stack;
	while (copy)
	{
		if (flag == 1)
		{
			if (copy->flag_above_median == 1)
				copy->place = info->current_size_a - copy->index;
			else
				copy->place = copy->index;
		}
		else
		{
			if (copy->flag_above_median == 1)
				copy->place = info->current_size_b - copy->index;
			else
				copy->place = copy->index;
		}
		copy = copy->next;
	}
}
