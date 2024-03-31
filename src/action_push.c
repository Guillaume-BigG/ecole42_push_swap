/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:51 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/26 16:13:25 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_initialize(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	temp = *dest;
	*dest = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		(*src)->previous = NULL;
	}
	else
		*src = NULL;
	(*dest)->next = temp;
	(*dest)->previous = NULL;
	(*dest)->index = -1;
	(*dest)->next->previous = *dest;
}

void	ft_stack_non_initialize(t_stack **dest, t_stack **src)
{
	t_stack	*copy;

	*dest = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		(*src)->previous = NULL;
	}
	else
		*src = NULL;
	(*dest)->previous = NULL;
	(*dest)->next = NULL;
	(*dest)->index = 0;
	copy = *src;
	while (copy)
	{
		copy->index -= 1;
		copy = copy->next;
	}
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*copy;

	if (!*dest)
	{
		ft_stack_non_initialize(dest, src);
	}
	else
	{
		ft_stack_initialize(dest, src);
		copy = *src;
		while (copy)
		{
			copy->index -= 1;
			copy = copy->next;
		}
		copy = *dest;
		while (copy)
		{
			copy->index += 1;
			copy = copy->next;
		}
	}
}

void	ft_push_to_a(t_stack **a, t_stack **b, t_info *info)
{
	if (!*b)
		return ;
	ft_push(a, b);
	write(1, "pa\n", 3);
	info->current_size_a += 1;
	info->current_size_b -= 1;
	info->current_max_a = ft_find_max_list(a);
	info->current_max_b = ft_find_max_list(b);
	info->current_min_a = ft_find_min_list(a);
	info->current_min_b = ft_find_min_list(b);
	info->median_a = info->current_size_a / 2;
	info->median_b = info->current_size_b / 2;
	ft_add_flag_median_all_a(a, info);
	ft_add_flag_median_all_b(b, info);
	ft_find_place_in_stack(a, info, 1);
	ft_find_place_in_stack(b, info, 0);
}

void	ft_push_to_b(t_stack **b, t_stack **a, t_info *info)
{
	if (!*a)
		return ;
	ft_push(b, a);
	write(1, "pb\n", 3);
	info->current_size_a -= 1;
	info->current_size_b += 1;
	info->current_max_a = ft_find_max_list(a);
	info->current_max_b = ft_find_max_list(b);
	info->current_min_a = ft_find_min_list(a);
	info->current_min_b = ft_find_min_list(b);
	info->median_a = info->current_size_a / 2;
	info->median_b = info->current_size_b / 2;
	ft_add_flag_median_all_a(a, info);
	ft_add_flag_median_all_b(b, info);
	ft_find_place_in_stack(a, info, 1);
	ft_find_place_in_stack(b, info, 0);
}
