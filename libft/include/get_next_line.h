/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:03:50 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 20:21:03 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../include/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*clean_stash(char *stash);
char	*read_line(char *stash);
char	*get_next_line(int fd);
char	*fill_stash(int fd, char *stash);

#endif
