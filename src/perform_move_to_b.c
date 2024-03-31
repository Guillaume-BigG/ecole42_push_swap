/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_move_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:53:07 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 19:53:08 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action_cheap_node_index_0(t_stack **a, t_info *info)
{
	t_stack	*copy;

	copy = info->cheapest_node;
	while (copy->index > 0)
	{
		if (copy->flag_above_median == 1)
			ft_rra(a, info);
		else
			ft_ra(a, info);
	}
}

void	ft_action_cheap_node_save_cost(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*copy;
	t_stack	*last;

	last = ft_last_stack(*b);
	copy = info->cheapest_node;
	if (copy->index != 0)
	{
		if (copy->flag_above_median == 0 && (*b)->rank == info->max_rank - 2
			&& last->rank != info->max_rank - 1)
			ft_rr(a, b, info);
	}
	while (copy->index != 0)
	{
		if (copy->flag_above_median == 1)
			ft_rra(a, info);
		else
			ft_ra(a, info);
	}
	if ((*b)->rank == info->max_rank - 2)
		ft_rb(b, info);
}

void	ft_action_cheap_node_save_cost2(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*copy;
	t_stack	*last;

	last = ft_last_stack(*b);
	copy = info->cheapest_node;
	if (copy->index != 0)
	{
		if (copy->flag_above_median == 0 && ((*b)->rank == info->max_rank - 1
				|| (*b)->rank == 0) && last->rank != info->max_rank - 2)
			ft_rr(a, b, info);
	}
	while (copy->index != 0)
	{
		if (copy->flag_above_median == 1)
			ft_rra(a, info);
		else
			ft_ra(a, info);
	}
	if ((*b)->rank == info->max_rank - 1 || (*b)->rank == 0)
		ft_rb(b, info);
}

int	ft_check_b_rank_all_equal(t_stack **b)
{
	t_stack	*copy;

	copy = *b;
	while (copy && copy->next)
	{
		if (copy->rank != copy->next->rank)
			return (0);
		copy = copy->next;
	}
	return (1);
}

void	ft_perform_action_cheap_node_a(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*copy;

	copy = info->cheapest_node;
	if (info->current_size_b < 2)
		ft_action_cheap_node_index_0(a, info);
	else if (info->max_rank == 2)
	{
		if (ft_check_b_rank_all_equal(b) == 1)
			ft_action_cheap_node_index_0(a, info);
		else if (ft_check_b_rank_all_equal(b) == 0)
			ft_action_cheap_node_save_cost(a, b, info);
	}
	else
		ft_action_cheap_node_save_cost2(a, b, info);
	ft_push_to_b(b, a, info);
}
