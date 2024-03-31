/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:50:17 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:11 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_int_tab(int *tab_int, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = tab_int[i];
	while (i < size)
	{
		if (tab_int[i] > temp)
			temp = tab_int[i];
		i++;
	}
	return (temp);
}

int	ft_find_max_list(t_stack **stack)
{
	t_stack	*copy;
	int		max;

	if (!*stack)
		return (0);
	copy = *stack;
	max = copy->reworked_value;
	while (copy)
	{
		if (copy->reworked_value > max)
			max = copy->reworked_value;
		copy = copy->next;
	}
	return (max);
}

int	ft_find_min_list(t_stack **stack)
{
	t_stack	*copy;
	int		min;

	if (!*stack)
		return (0);
	copy = *stack;
	min = copy->reworked_value;
	while (copy)
	{
		if (copy->reworked_value < min)
			min = copy->reworked_value;
		copy = copy->next;
	}
	return (min);
}

void	ft_calculate_max_rank_in_b(t_stack **b, t_info *info)
{
	t_stack	*copy;

	if (!*b)
		return ;
	copy = *b;
	info->max_rank_in_b = copy->rank;
	while (copy)
	{
		if (copy->rank > info->max_rank_in_b)
			info->max_rank_in_b = copy->rank;
		copy = copy->next;
	}
}

int	*ft_atoi_tab(char **tab)
{
	int	i;
	int	length;
	int	*tab_int;

	length = 0;
	while (tab[length])
		length++;
	i = -1;
	tab_int = malloc(sizeof(int) * length);
	if (!tab_int)
	{
		free_double_tab_char(tab);
		exit(1);
	}
	while (tab[++i])
		tab_int[i] = ft_atoi(tab[i]);
	return (tab_int);
}
