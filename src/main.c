/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:08:39 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 18:54:40 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**tab_string;
	int		*tab_int;
	t_info	*info;
	t_stack	*a;
	t_stack	*b;

	tab_string = ft_check_numb_arg(argc, argv);
	tab_int = ft_atoi_tab(tab_string);
	info = ft_initialize_info(tab_string, tab_int);
	free_double_tab_char(tab_string);
	a = ft_initialize_stack_a(tab_int, info);
	ft_add_information_stack_a(&a, info);
	if (ft_check_sorting_index(a))
		ft_free_all(info, a);
	b = NULL;
	ft_sorting_stack(&a, &b, info);
	ft_free_all(info, a);
	return (0);
}
