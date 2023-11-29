/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:49:28 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/29 17:16:11 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	find_n(char const *str, char a)
{
	size_t	k;

	k = 0;
	while (*str)
	{
		if (*str != a)
		{
			while (*str != a && *str)
				str++;
			k++;
		}
		else
			str++;
	}
	return (k + 2);
}

char	**ft_split_plus(char const *s, char c, char *file)
{
	size_t	l;
	size_t	k;
	char	**splitted_arr;

	k = 0;
	splitted_arr = (char **)malloc((find_n(s, c)) * sizeof(char *));
	if (!splitted_arr)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!ft_strchr(s, c))
			l = ft_strlen(s);
		else
			l = ft_strchr(s, c) - s;
		if (*s)
			splitted_arr[k++] = ft_substr(s, 0, l);
		s += l;
	}
	splitted_arr[k] = ft_substr(file, 0, ft_strlen(file));
	splitted_arr[k + 1] = NULL;
	return (splitted_arr);
}
