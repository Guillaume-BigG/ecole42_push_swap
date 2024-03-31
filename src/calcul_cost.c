/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:31:36 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:11 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_cheapest_node_and_rank_count(t_stack **a, t_info *info)
{
	t_stack	*copy_a;
	int		temp_low_cost;
	int		count;

	copy_a = *a;
	count = 0;
	temp_low_cost = copy_a->cost;
	info->cheapest_node = copy_a;
	while (copy_a)
	{
		if (copy_a->rank != info->max_rank)
		{
			if (copy_a->cost < temp_low_cost)
			{
				temp_low_cost = copy_a->cost;
				info->cheapest_node = copy_a;
			}
			count++;
		}
		copy_a = copy_a->next;
	}
	info->number_of_node_current_rank = count;
}

void	ft_determine_cost_for_b(t_stack **b, t_info *info)
{
	t_stack	*copy_b;

	copy_b = *b;
	while (copy_b)
	{
		if (copy_b->flag_above_median == copy_b->asso_node->flag_above_median)
		{
			if (copy_b->place > copy_b->asso_node->place)
				copy_b->cost = copy_b->place;
			else
				copy_b->cost = copy_b->asso_node->place;
		}
		else
		{
			if (info->current_size_a > info->current_size_b
				&& copy_b->place > copy_b->asso_node->place)
				copy_b->cost = copy_b->place;
			else if (info->current_size_a < info->current_size_b
				&& copy_b->place < copy_b->asso_node->place)
				copy_b->cost = copy_b->asso_node->place;
			else
				copy_b->cost = copy_b->place + copy_b->asso_node->place;
		}
		copy_b = copy_b->next;
	}
}

void	ft_calculate_cost_and_rank_count_for_a(t_stack **a, t_info *info)
{
	t_stack	*copy_a;

	copy_a = *a;
	while (copy_a)
	{
		if (copy_a->rank != info->max_rank)
		{
			if (copy_a->flag_above_median == 1)
				copy_a->cost = copy_a->place + 1;
			else
				copy_a->cost = copy_a->index + 1;
		}
		copy_a = copy_a->next;
	}
	ft_find_cheapest_node_and_rank_count(a, info);
}

void	ft_find_cheapest_node_b(t_stack **b, t_info *info)
{
	t_stack	*copy_b;
	int		temp_low_cost;

	copy_b = *b;
	while (copy_b->rank != info->max_rank_in_b)
		copy_b = copy_b->next;
	temp_low_cost = copy_b->cost;
	info->cheapest_node = copy_b;
	while (copy_b)
	{
		if (copy_b->cost < temp_low_cost && copy_b->rank == info->max_rank_in_b)
		{
			temp_low_cost = copy_b->cost;
			info->cheapest_node = copy_b;
		}
		copy_b = copy_b->next;
	}
}
