/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumebeaudoin <guillaumebeaudoin@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:04:06 by gbeaudoi          #+#    #+#             */
/*   Updated: 2023/12/27 12:06:33 by guillaumebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		new_stash = ft_substr(stash, i + 1, len - i);
	free(stash);
	return (new_stash);
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
		stash = ft_strdup("");
	while (read_value != 0 && !ft_strchr(stash, '\n'))
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1)
			return (free(stash), free(buf), NULL);
		buf[read_value] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash || stash[0] == 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = read_line(stash);
	stash = clean_stash(stash);
	return (line);
}
