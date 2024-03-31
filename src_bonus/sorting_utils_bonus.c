/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:34:31 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/26 17:17:25 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	*ft_atoi_tab_bonus(char **tab)
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
		free_double_tab_char_bonus(tab);
		ft_wait_push_swap();
		exit(1);
	}
	while (tab[++i])
		tab_int[i] = ft_atoi(tab[i]);
	return (tab_int);
}

int	ft_find_size_bonus(char **tab_str)
{
	int	length;

	length = 0;
	while (tab_str[length])
		length++;
	return (length);
}

int	ft_check_sorting_bonus(t_stack **stack)
{
	t_stack	*copy;

	copy = *stack;
	while (copy && copy->next)
	{
		if (copy->real_value > copy->next->real_value)
			return (0);
		copy = copy->next;
	}
	return (1);
}
