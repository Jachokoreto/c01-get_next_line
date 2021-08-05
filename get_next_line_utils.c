/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jatan <jatan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:41:19 by jatan             #+#    #+#             */
/*   Updated: 2021/08/05 12:03:39 by jatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s);
	ptr = (char *)s;
	while (len-- >= 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (s == NULL)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (s - s1_len - s2_len);
}
