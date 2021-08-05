/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:22 by jatan             #+#    #+#             */
/*   Updated: 2021/08/05 12:51:46 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*s;

	if (fd < 0)
		return (NULL);
	while (fd >= 0)
	{
		read(fd, &buffer, BUFFER_SIZE);
		
	}
}

// use strchr and strjoin
