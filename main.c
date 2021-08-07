/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:04:53 by jatan             #+#    #+#             */
/*   Updated: 2021/08/08 00:02:08 by jatan            ###   ########.fr       */
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

	fd = open("test", O_RDWR);
	i = 0;
	while (i++ < 10)
	{
		s = get_next_line(fd);
		printf(",%s", s);
		free(s);
	}
}
