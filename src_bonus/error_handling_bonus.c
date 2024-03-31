/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:33:43 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 16:54:29 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	free_lists_bonus(t_stack *stack)
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

void	ft_exit(void)
{
	ft_wait_push_swap();
	exit(1);
}

void	ft_write_error_na_bonus(void)
{
	ft_wait_push_swap();
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_write_error_bonus(t_stack *a, t_stack *b)
{
	ft_wait_push_swap();
	free_lists_bonus(a);
	free_lists_bonus(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_double_tab_char_bonus(char **tab)
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
