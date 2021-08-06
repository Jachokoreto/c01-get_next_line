/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2021/08/06 22:13:27 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*string;
	char	*s;
	int		r;

	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	string = (char *)calloc(1, 1);
	if (!buffer || !string)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (buffer == NULL)
			return (NULL);
		s = ft_strchr(buffer, '\n');
		if (s != NULL)
			*s = 0;
		s = string;
		string = ft_strjoin(s, buffer);
		free(s);
	}
	free(buffer);
	return (string);
}
