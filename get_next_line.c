/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2021/08/06 17:22:52 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*string;

	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		*(ft_strchr(buffer, '\n')) = 0;
	}
	else
		return (NULL);
	string = ft_strdup(buffer);
	free(buffer);
	return (string);
}
