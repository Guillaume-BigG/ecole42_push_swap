/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:08:20 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/20 20:07:37 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_argv2(char **argv)
{
	int	i;
	int	j;
	int	length;
	int	count;

	i = -1;
	j = 0;
	if (argv[1][j] == '\0')
		ft_write_error();
	count = ft_count_digit(argv);
	length = ft_strlen(argv[1]);
	while (++i < count)
	{
		while (argv[1][j] == ' ' || (argv[1][j] >= 9 && argv[1][j] <= 13))
			j++;
		if (argv[1][j] == '+' || argv[1][j] == '-')
			j++;
		while (ft_isdigit(argv[1][j]))
			j++;
		while (argv[1][j] == ' ' || (argv[1][j] >= 9 && argv[1][j] <= 13))
			j++;
	}
	if (j != length)
		ft_write_error();
	return (count);
}

void	ft_check_mult_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			ft_write_error();
		length = ft_strlen(argv[i]);
		while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (ft_isdigit(argv[i][j]))
			j++;
		while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
			j++;
		if (j != length || (j == length && (argv[i][--j] == '+'
				|| argv[i][j] == '-')))
			ft_write_error();
		i++;
	}
}

void	check_overflow(int loop, char **tab)
{
	int			i;
	long long	temp;
	long		length;

	i = 0;
	while (i < loop)
	{
		temp = ft_atol(tab[i]);
		length = ft_strlen_revised(tab[i]);
		if ((length == 10 && tab[i][0] != '-' && ft_strncmp(tab[i],
				INT_MAX_STRING, 10) > 0 && temp > INT_MAX) || (length == 11
				&& tab[i][0] == '-' && ft_strncmp(tab[i], INT_MIN_STRING,
				11) > 0 && temp < INT_MIN) || length > 11)
		{
			free_double_tab_char(tab);
			ft_write_error();
		}
		i++;
	}
}

void	check_duplicate(int loop, char **tab)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < loop)
	{
		temp = ft_atoi(tab[i]);
		j = i;
		while (++j < loop)
		{
			if (temp == ft_atoi(tab[j]))
			{
				free_double_tab_char(tab);
				ft_write_error();
			}
		}
		i++;
	}
}

char	**ft_check_numb_arg(int argc, char **argv)
{
	char	**tab;
	int		count;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		count = ft_check_argv2(argv);
		tab = ft_split(argv[1], ' ');
		if (tab == NULL)
			exit(1);
	}
	else
	{
		ft_check_mult_argv(argc, argv);
		count = argc - 1;
		tab = ft_argv_to_one_line(argv, argc, 0);
	}
	check_overflow(count, tab);
	check_duplicate(count, tab);
	return (tab);
}
