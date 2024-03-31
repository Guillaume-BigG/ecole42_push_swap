/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:34:31 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/25 16:25:46 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorting_index(t_stack *stack)
{
	t_stack	*copie;

	copie = stack;
	while (copie)
	{
		if (copie->index != copie->reworked_value)
			return (0);
		copie = copie->next;
	}
	return (1);
}

int	ft_find_size(char **tab_str)
{
	int	length;

	length = 0;
	while (tab_str[length])
		length++;
	return (length);
}

void	ft_perform_action_sort_stack(t_stack **a, t_stack **b, t_info *info,
		int flag)
{
	t_stack	*max;
	t_stack	*min;

	if (flag == 0)
	{
		max = ft_find_max_list_address(b);
		while (max->index != 0)
		{
			if (max->flag_above_median)
				ft_rrb(b, info);
			else
				ft_rb(b, info);
		}
	}
	else
	{
		min = ft_find_min_list_address(a);
		while (min->index != 0)
		{
			if (min->flag_above_median)
				ft_rra(a, info);
			else
				ft_ra(a, info);
		}
	}
}

void	ft_sort_b(t_stack **b, t_info *info)
{
	t_stack	*last;
	t_stack	*copy;

	if (!*b)
		return ;
	copy = *b;
	last = ft_last_stack(copy);
	ft_calculate_max_rank_in_b(b, info);
	while (last->rank == info->max_rank_in_b)
	{
		ft_rrb(b, info);
		last = ft_last_stack(copy);
	}
}
