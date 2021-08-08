/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2021/08/08 17:15:13 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	join_line(char **line, char *string, int *r);

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		r;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	r = read(fd, buffer, 0);
	line = NULL;
	if (r < 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	r = 1;
	while (r > 0)
	{
		join_line(&line, buffer, &r);
		if (r == 0)
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
		buffer[r] = 0;
	}
	free(buffer);
	if (!*line)
		return (NULL);
	return (line);
}

void	join_line(char **line, char *str, int *r)
{
	static char	*store;
	char		*tmp;

	if (store)
	{
		*line = ft_strdup(store);
		free(store);
		store = NULL;
	}
	else if (!*line)
		*line = ft_strdup("");
	if (*str)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, str);
		free(tmp);
	}
	tmp = ft_strchr(*line, '\n');
	if (tmp)
	{
		store = ft_strdup(tmp + 1);
		*(++tmp) = '\0';
		*r = 0;
	}
}
