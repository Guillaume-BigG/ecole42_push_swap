/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:20:49 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/26 21:39:59 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max_list_address(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*max;
	int		max_nbr;

	if (!*stack)
		return (0);
	copy = *stack;
	max_nbr = copy->reworked_value;
	max = copy;
	while (copy)
	{
		if (copy->reworked_value > max_nbr)
		{
			max_nbr = copy->reworked_value;
			max = copy;
		}
		copy = copy->next;
	}
	return (max);
}

t_stack	*ft_find_min_list_address(t_stack **stack)
{
	t_stack	*copy;
	t_stack	*min;
	int		min_nbr;

	if (!*stack)
		return (0);
	copy = *stack;
	min_nbr = copy->reworked_value;
	min = copy;
	while (copy)
	{
		if (copy->reworked_value < min_nbr)
		{
			min_nbr = copy->reworked_value;
			min = copy;
		}
		copy = copy->next;
	}
	return (min);
}

t_stack	*ft_new_node(int integer, int i)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->cost = INT_MAX;
	node->index = i;
	node->real_value = integer;
	node->reworked_value = 0;
	node->percentile = 0;
	node->rank = 0;
	node->flag_dealt = 0;
	node->flag_above_median = 0;
	node->place = 0;
	node->asso_node = NULL;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack	*ft_last_stack(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

void	ft_stack_add_to_back(t_stack **a, t_stack *new_node)
{
	t_stack	*last_node;

	if (!a || !new_node)
		return ;
	if (*a)
	{
		last_node = ft_last_stack(*a);
		new_node->previous = last_node;
		last_node->next = new_node;
	}
	else
	{
		new_node->previous = *a;
		*a = new_node;
	}
}
