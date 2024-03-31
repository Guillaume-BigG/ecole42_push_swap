/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:45:36 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 18:54:23 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	check_command(char *cmd, t_stack **a, t_stack **b)
{
	if (ft_strncmp(cmd, "sa", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_sa_bonus(a), 1);
	else if (ft_strncmp(cmd, "pa", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_push_to_a_bonus(a, b), 1);
	else if (ft_strncmp(cmd, "ra", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_ra_bonus(a), 1);
	else if (ft_strncmp(cmd, "rra", 3) == 0 && ft_strlen(cmd) == 4)
		return (ft_rra_bonus(a), 1);
	else if (ft_strncmp(cmd, "sb", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_sb_bonus(b), 1);
	else if (ft_strncmp(cmd, "pb", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_push_to_b_bonus(b, a), 1);
	else if (ft_strncmp(cmd, "rb", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_rb_bonus(b), 1);
	else if (ft_strncmp(cmd, "rrb", 3) == 0 && ft_strlen(cmd) == 4)
		return (ft_rrb_bonus(b), 1);
	else if (ft_strncmp(cmd, "ss", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_ss_bonus(a, b), 1);
	else if (ft_strncmp(cmd, "rr", 2) == 0 && ft_strlen(cmd) == 3)
		return (ft_rr_bonus(a, b), 1);
	else if (ft_strncmp(cmd, "rrr", 3) == 0 && ft_strlen(cmd) == 4)
		return (ft_rrr_bonus(a, b), 1);
	else
		return (-1);
}

int	ft_get_command(t_stack **a, t_stack **b)
{
	char	*command;
	int		flag;

	flag = 1;
	command = get_next_line_bonus(0);
	while (command)
	{
		if (check_command(command, a, b) == -1)
			flag = 0;
		free(command);
		command = get_next_line_bonus(0);
	}
	free(command);
	return (flag);
}

void	ft_wait_push_swap(void)
{
	char	*command;

	command = get_next_line_bonus(0);
	while (command)
	{
		if (!command)
			break ;
		free(command);
		command = get_next_line_bonus(0);
	}
	free(command);
}

int	main(int argc, char *argv[])
{
	char	**tab_string;
	int		*tab_int;
	t_stack	*a;
	t_stack	*b;
	int		flag;

	tab_string = ft_check_numb_arg_bonus(argc, argv);
	tab_int = ft_atoi_tab_bonus(tab_string);
	a = ft_initialize_stack_a_bonus(tab_int, tab_string);
	b = NULL;
	flag = ft_get_command(&a, &b);
	if (flag == 0)
	{
		free_lists_bonus(a);
		free_lists_bonus(b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_check_sorting_bonus(&a) == 1 && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lists_bonus(a);
	free_lists_bonus(b);
	return (0);
}
