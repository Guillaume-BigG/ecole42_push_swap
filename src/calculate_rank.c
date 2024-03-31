/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:57:09 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 20:03:29 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_temp(t_stack **stack, t_stack *copy_send, int flag)
{
	int		temp;
	t_stack	*copy;

	copy = *stack;
	if (flag == 1)
	{
		while (copy && copy->reworked_value > copy_send->reworked_value)
			copy = copy->next;
		temp = copy_send->reworked_value - copy->reworked_value;
	}
	else
	{
		while (copy && copy->reworked_value < copy_send->reworked_value)
			copy = copy->next;
		temp = copy->reworked_value - copy_send->reworked_value;
	}
	return (temp);
}

void	find_node(t_stack *node1, t_stack *node2, int temp, int flag)
{
	int	numb;

	while (node2)
	{
		if (flag == 1)
			numb = node1->reworked_value - node2->reworked_value;
		else
			numb = node2->reworked_value - node1->reworked_value;
		if (numb <= temp && numb > 0)
		{
			node1->asso_node = node2;
			temp = numb;
		}
		node2 = node2->next;
	}
}

void	ft_determine_info_for_rank(t_info *info, int flag)
{
	if (flag == 1)
	{
		if (info->current_size_a / 2 == 0 || info->current_size_a / 3 == 0)
			info->one_third = 1;
		else
		{
			if (info->size < 500)
			{
				info->one_third = info->current_size_a / 2;
				info->two_third = info->one_third * 2;
			}
			else
			{
				info->one_third = info->current_size_a / 3;
				info->two_third = info->one_third * 2;
			}
		}
	}
}

void	ft_calculate_rank(t_stack **a, t_info *info, int flag)
{
	t_stack	*copy;

	copy = *a;
	ft_determine_info_for_rank(info, flag);
	ft_recalculate_percentile(a, info);
	while (copy)
	{
		if (copy->percentile < info->one_third)
			copy->rank = info->max_rank;
		else if (copy->percentile < info->two_third)
			copy->rank = info->max_rank + 1;
		else
			copy->rank = info->max_rank + 2;
		copy = copy->next;
	}
	info->max_rank += 2;
}
