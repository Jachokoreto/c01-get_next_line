/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2021/08/07 23:54:26 by jatan            ###   ########.fr       */
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
	join_line(&line, NULL, &r);
	r = read(fd, buffer, BUFFER_SIZE);
	if ((r <= 0 && *line == '\0') || !buffer)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	while (r > 0)
	{
		buffer[r] = 0;
		join_line(&line, buffer, &r);
		if (r == 0)
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}

void	join_line(char **line, char *str, int *r)
{
	static char	*store;
	char		*tmp;

	if (store)
	{
		*line = ft_strdup(store);
		store = NULL;
	}
	else if (str)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, str);
		free(tmp);
	}
	else
		*line = ft_strdup("");
	if (ft_strchr(*line, '\n'))
	{
		tmp = ft_strchr(*line, '\n');
		store = ft_strdup(tmp + 1);
		*(++tmp) = '\0';
//			printf("!!!");
		*r = 0;
	}
}
