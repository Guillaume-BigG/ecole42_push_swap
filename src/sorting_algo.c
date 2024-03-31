/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:45:13 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 20:06:12 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_less_3(t_stack **a, t_stack **b, t_info *info)
{
	(void)b;
	if (info->size < 3)
		ft_sa(a, info);
	else
	{
		if ((*a)->reworked_value == info->current_max_a)
			ft_ra(a, info);
		else if ((*a)->next->reworked_value == info->current_max_a)
			ft_rra(a, info);
		if ((*a)->reworked_value > (*a)->next->reworked_value)
			ft_sa(a, info);
	}
}

void	ft_sort_infinite(t_stack **a, t_stack **b, t_info *info)
{
	while (info->current_size_a > 3)
	{
		ft_calculate_cost_and_rank_count_for_a(a, info);
		while (info->number_of_node_current_rank > 0
			&& info->current_size_a > 3)
		{
			ft_perform_action_cheap_node_a(a, b, info);
			ft_calculate_cost_and_rank_count_for_a(a, info);
		}
		ft_calculate_rank(a, info, 1);
	}
	ft_sort_less_3(a, b, info);
	while (info->current_size_b > 0)
	{
		ft_calculate_max_rank_in_b(b, info);
		ft_find_asso_node_for_b(b, a, info, 0);
		ft_determine_cost_for_b(b, info);
		ft_find_cheapest_node_b(b, info);
		ft_perform_action_cheap_node_b(a, b, info);
	}
	if (!ft_check_sorting_index(*a))
		ft_perform_action_sort_stack(a, b, info, 1);
}

void	ft_sorting_stack(t_stack **a, t_stack **b, t_info *info)
{
	if (info->size <= 3)
		ft_sort_less_3(a, b, info);
	else
		ft_sort_infinite(a, b, info);
}
