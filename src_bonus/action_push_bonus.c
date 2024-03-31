/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:51 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/26 16:13:03 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_stack_initialize_bonus(t_stack **dest, t_stack **src)
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
	(*dest)->next->previous = *dest;
}

void	ft_stack_non_initialize_bonus(t_stack **dest, t_stack **src)
{
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
}

void	ft_push_bonus(t_stack **dest, t_stack **src)
{
	if (!*dest)
		ft_stack_non_initialize_bonus(dest, src);
	else
		ft_stack_initialize_bonus(dest, src);
}

void	ft_push_to_a_bonus(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	ft_push_bonus(a, b);
}

void	ft_push_to_b_bonus(t_stack **b, t_stack **a)
{
	if (!*a)
		return ;
	ft_push_bonus(b, a);
}
