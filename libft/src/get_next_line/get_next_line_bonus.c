/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:04:06 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/03/28 16:31:56 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_stash(char *stash)
{
	int		len;
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = ft_strlen(stash);
	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		return (NULL);
	}
	else
	{
		new_stash = ft_substr(stash, i + 1, len - i);
		free(stash);
		return (new_stash);
	}
}

char	*read_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!ft_strchr(stash, '\n'))
		line = ft_strdup(stash);
	else
		line = ft_substr(stash, 0, i + 1);
	return (line);
}

char	*fill_stash(int fd, char *stash)
{
	ssize_t	read_value;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_value = 1;
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
			return (free(buf), NULL);
	}
	while (read_value != 0 && !ft_strchr(stash, '\n'))
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1)
			return (free(stash), free(buf), NULL);
		buf[read_value] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (stash == NULL)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	*stash[10000];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash[fd] = fill_stash(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = read_line(stash[fd]);
	if (line == NULL)
		return (free(stash[fd]), NULL);
	stash[fd] = clean_stash(stash[fd]);
	if (stash[fd] == NULL)
	{
		free(stash[fd]);
	}
	return (line);
}
