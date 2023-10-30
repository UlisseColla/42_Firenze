/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:16:49 by ucolla            #+#    #+#             */
/*   Updated: 2023/10/30 15:54:20 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;
	
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	a = 0;
	b = 0;
	// if (!s1 || !s2)
	// 	return (NULL);
	while (s1[a] != '\0')
	{
		ret[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		ret[a] = s2[b];
		a++;
		b++;
	}
	ret[a] = '\0';
	printf("\nstrjoin: %s\n", ret);
	return (ret);
}