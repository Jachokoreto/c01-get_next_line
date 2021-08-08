/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:04:53 by jatan             #+#    #+#             */
/*   Updated: 2021/08/08 21:24:30 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("test", O_RDWR);
	s = get_next_line(fd);
	while (s != NULL && i < 10)
	{
		printf(">%s", s);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free(s);
}
