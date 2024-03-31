/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:19:17 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:11 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_info_rank_number(t_info **info)
{
	if ((*info)->size < 500)
	{
		(*info)->max_rank_in_b = 0;
		(*info)->max_rank = 0;
		(*info)->one_third = (*info)->size / 2;
		(*info)->two_third = (*info)->one_third * 2;
	}
	else
	{
		(*info)->max_rank_in_b = 0;
		(*info)->max_rank = 0;
		(*info)->one_third = (*info)->size / 6;
		(*info)->two_third = (*info)->one_third * 2;
	}
}

t_info	*ft_initialize_info(char **tab_string, int *tab_int)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
	{
		free_double_tab_char(tab_string);
		free(tab_int);
		exit(1);
	}
	info->size = ft_find_size(tab_string);
	info->max = ft_find_max_int_tab(tab_int, info->size);
	info->max_reworked = info->size - 1;
	info->current_size_a = info->size;
	info->current_size_b = 0;
	ft_add_info_rank_number(&info);
	info->current_max_a = info->max_reworked;
	info->current_max_b = 0;
	info->current_min_a = 0;
	info->current_min_b = 0;
	info->median_a = info->size / 2;
	info->median_b = 0;
	info->cheapest_node = NULL;
	info->number_of_node_current_rank = 0;
	return (info);
}
