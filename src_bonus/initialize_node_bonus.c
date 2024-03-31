/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_node_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:47:35 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/25 19:21:30 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_stack	*ft_initialize_stack_a_bonus(int *tab_int, char **tab_string)
{
	int		i;
	t_stack	*a;
	t_stack	*new_node;
	int		size;

	a = NULL;
	i = -1;
	size = ft_find_size_bonus(tab_string);
	while (++i < size)
	{
		new_node = ft_new_node_bonus(tab_int[i]);
		if (new_node == NULL)
		{
			free(tab_int);
			free_double_tab_char_bonus(tab_string);
			free_lists_bonus(a);
			exit(1);
		}
		ft_stack_add_to_back_bonus(&a, new_node);
	}
	free(tab_int);
	free_double_tab_char_bonus(tab_string);
	return (a);
}
