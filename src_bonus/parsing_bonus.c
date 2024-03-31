/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:08:20 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/26 17:47:39 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_check_argv2_bonus(char **argv)
{
	int	i;
	int	j;
	int	length;
	int	count;

	i = -1;
	j = 0;
	if (argv[1][j] == '\0')
		ft_write_error_na_bonus();
	count = ft_count_digit_bonus(argv);
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
		ft_write_error_na_bonus();
	return (count);
}

void	ft_check_mult_argv_bonus(int argc, char **argv)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			ft_write_error_na_bonus();
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
			ft_write_error_na_bonus();
		i++;
	}
}

void	check_overflow_bonus(int loop, char **tab)
{
	int			i;
	long long	temp;
	long		length;

	i = 0;
	while (i < loop)
	{
		temp = ft_atol_bonus(tab[i]);
		length = ft_strlen_revised_bonus(tab[i]);
		if ((length == 10 && tab[i][0] != '-' && ft_strncmp(tab[i],
				INT_MAX_STRING, 10) > 0 && temp > INT_MAX) || (length == 11
				&& tab[i][0] == '-' && ft_strncmp(tab[i], INT_MIN_STRING,
					11) > 0 && temp < INT_MIN) || length > 11)
		{
			free_double_tab_char_bonus(tab);
			ft_write_error_na_bonus();
		}
		i++;
	}
}

void	check_duplicate_bonus(int loop, char **tab)
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
				free_double_tab_char_bonus(tab);
				ft_write_error_na_bonus();
			}
		}
		i++;
	}
}

char	**ft_check_numb_arg_bonus(int argc, char **argv)
{
	char	**tab;
	int		count;

	if (argc == 1)
		ft_exit();
	if (argc == 2)
	{
		count = ft_check_argv2_bonus(argv);
		tab = ft_split(argv[1], ' ');
		if (tab == NULL)
			ft_exit();
	}
	else
	{
		ft_check_mult_argv_bonus(argc, argv);
		count = argc - 1;
		tab = ft_argv_to_one_line_bonus(argv, argc, 0);
	}
	check_overflow_bonus(count, tab);
	check_duplicate_bonus(count, tab);
	return (tab);
}
