/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2021/08/07 11:56:55 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	join_line(char **string, char *buffer);

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*string;
	char	*s;
	int		r;

	r = read(fd, &buffer, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	string = (char *)calloc(1, 1);
	while (r > 0)
	{
		buffer[r] = 0;
		s = ft_strchr(buffer, '\n');
		if (s != NULL)
		{
			*s = 0;
			join_line(&string, buffer);
			break ;
		}
		join_line(&string, buffer);
		r = read(fd, &buffer, BUFFER_SIZE);
	}
	return (string);
}

void	join_line(char **string, char *buffer)
{
	char	*s;

	s = *string;
	*string = ft_strjoin(s, buffer);
	free(s);
}
