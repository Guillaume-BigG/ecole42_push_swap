/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_node_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:47:35 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 19:41:22 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_flag_dealt(t_stack **a)
{
	t_stack	*copy;

	copy = *a;
	while (copy)
	{
		copy->flag_dealt = 0;
		copy = copy->next;
	}
}

int	ft_find_second_max(t_stack *a, int temp_max)
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
			if ((i->real_value >= j->real_value) && (i->flag_dealt == 0)
				&& (i->real_value != temp_max) && (i->real_value > second_max))
				second_max = i->real_value;
			j = j->next;
		}
		i = i->next;
	}
	return (second_max);
}

void	ft_add_flag_median(t_stack **a, t_info *info)
{
	t_stack	*copy;

	copy = *a;
	while (copy)
	{
		if (copy->index > info->median_a)
			copy->flag_above_median = 1;
		else
			copy->flag_above_median = 0;
		copy = copy->next;
	}
	ft_find_place_in_stack(a, info, 1);
	ft_calculate_rank(a, info, 0);
}

void	ft_add_information_stack_a(t_stack **a, t_info *info)
{
	int		temp_max;
	int		second_max;
	int		count;
	t_stack	*copy;

	copy = *a;
	count = info->size;
	temp_max = info->max;
	while (--count >= 0)
	{
		second_max = ft_find_second_max(copy, temp_max);
		while (copy)
		{
			if (copy->real_value == temp_max)
			{
				copy->reworked_value = count;
				copy->percentile = count;
				copy->flag_dealt = 1;
			}
			copy = copy->next;
		}
		temp_max = second_max;
		copy = *a;
	}
	ft_add_flag_median(a, info);
}

t_stack	*ft_initialize_stack_a(int *tab_int, t_info *info)
{
	int		i;
	t_stack	*a;
	t_stack	*new_node;

	a = NULL;
	i = -1;
	while (++i < info->size)
	{
		new_node = ft_new_node(tab_int[i], i);
		if (new_node == NULL)
		{
			free(tab_int);
			free(info);
			free_lists(a);
			exit(1);
		}
		ft_stack_add_to_back(&a, new_node);
	}
	free(tab_int);
	return (a);
}
