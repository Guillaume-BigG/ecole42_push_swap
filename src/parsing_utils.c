/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:48:46 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/28 16:10:17 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long		i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

int	ft_count_digit(char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) && (argv[1][i + 1] == ' ' || argv[1][i
				+ 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	**ft_argv_to_one_line(char **argv, int argc, int i)
{
	char	*bigline;
	char	**tab;

	bigline = ft_calloc(1, sizeof(char));
	while (argv[++i])
	{
		bigline = ft_strjoinfree(bigline, argv[i]);
		if (bigline == NULL)
			exit(1);
		if (i != (argc - 1))
		{
			bigline = ft_strjoinfree(bigline, " ");
			if (bigline == NULL)
				exit(1);
		}
	}
	tab = ft_split(bigline, ' ');
	if (tab == NULL)
	{
		free(bigline);
		exit(1);
	}
	free(bigline);
	return (tab);
}

long	ft_strlen_revised(char *str)
{
	long	i;
	long	length;

	i = 0;
	length = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '+'
		|| str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			length++;
		i++;
		if (!str[i])
			length++;
	}
	while (ft_isdigit(str[i]))
	{
		length++;
		i++;
	}
	return (length);
}
