/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:33:43 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 16:56:07 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lists(t_stack *stack)
{
	t_stack	*temp_node;

	while ((stack))
	{
		temp_node = stack->next;
		free(stack);
		stack = temp_node;
	}
	free(stack);
}

void	ft_free_all(t_info *info, t_stack *a)
{
	free(info);
	free_lists(a);
	exit(1);
}

void	ft_write_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_double_tab_char(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
