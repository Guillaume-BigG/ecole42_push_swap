/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_move_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:53:07 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 19:53:03 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_second_max_for_percentile(t_stack *a, int temp_max)
{
	int		second_max;
	t_stack	*i;
	t_stack	*j;

	i = a;
	second_max = INT_MIN;
	while (i)
	{
		j = i;
		while (j)
		{
			if ((i->reworked_value >= j->reworked_value) && (i->flag_dealt == 0)
				&& (i->reworked_value != temp_max)
				&& (i->reworked_value > second_max))
				second_max = i->reworked_value;
			j = j->next;
		}
		i = i->next;
	}
	return (second_max);
}

void	ft_recalculate_percentile(t_stack **a, t_info *info)
{
	int		temp_max;
	int		count;
	t_stack	*copy;
	int		second_max;

	copy = *a;
	count = info->current_size_a;
	temp_max = info->current_max_a;
	ft_reset_flag_dealt(a);
	while (--count >= 0)
	{
		second_max = ft_find_second_max_for_percentile(copy, temp_max);
		while (copy)
		{
			if (copy->reworked_value == temp_max)
			{
				copy->percentile = count;
				copy->flag_dealt = 1;
			}
			copy = copy->next;
		}
		temp_max = second_max;
		copy = *a;
	}
}

void	ft_action_similar_flag_median_b(t_stack **a, t_stack **b, t_info *info,
		t_stack *copy)
{
	t_stack	*asso_node;

	asso_node = copy->asso_node;
	while (copy->index > 0)
	{
		if (copy->flag_above_median == 1)
			ft_rrb(b, info);
		else
			ft_rb(b, info);
	}
	while (asso_node->index > 0)
	{
		if (asso_node->flag_above_median == 1)
			ft_rra(a, info);
		else
			ft_ra(a, info);
	}
}

void	ft_perform_action_cheap_node_b(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*copy;
	t_stack	*asso_node;

	copy = info->cheapest_node;
	asso_node = copy->asso_node;
	while (copy->index > 0 && asso_node->index > 0)
	{
		if (copy->flag_above_median == asso_node->flag_above_median
			&& copy->flag_above_median == 1)
			ft_rrr(a, b, info);
		else if (copy->flag_above_median == asso_node->flag_above_median
			&& copy->flag_above_median == 0)
			ft_rr(a, b, info);
		else
		{
			if (copy->flag_above_median == 1)
				ft_rrb(b, info);
			else
				ft_rb(b, info);
		}
	}
	ft_action_similar_flag_median_b(a, b, info, copy);
	ft_push_to_a(a, b, info);
}
