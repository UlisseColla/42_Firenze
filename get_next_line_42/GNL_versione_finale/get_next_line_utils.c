/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:24 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/07 12:46:30 by ucolla           ###   ########.fr       */
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

	ret = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	a = 0;
	b = 0;
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
	return (ret);
}

char	*ft_strchr(char *str, char a)
{
	while (*str != a && *str)
		str++;
	if (!*str)
		return (NULL);
	return (str + 1);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	size_t	k;

	copy = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	k = 0;
	if (!copy)
		return (NULL);
	while (str[k] != '\0')
	{
		copy[k] = str[k];
		k++;
	}
	copy[k] = '\0';
	return (copy);
}

/* char	*ft_substr(char *str_to_search, char c_to_find)
{
	size_t	l;
	size_t	k;
	char	*copy;

	l = ft_strlen(str_to_search) - ft_strlen(ft_strchr(str_to_search ,c_to_find));
	k = 0;
	copy = (char *)ft_calloc(l + 2, sizeof(char));
	if (!copy)
	{
		free (copy);
		return (NULL);
	}
	while (str_to_search[k] != c_to_find)
	{
		copy[k] = str_to_search[k];
		k++;
	}
	copy[k++] = '\n';
	copy[k++] = '\0';
	return (copy);
} */

/* char	*ft_strcpy(char *str_to_copy)
{
	char	*str;
	size_t	k;

	str = "";
	k = 0;
	if (!str_to_copy)
		return (NULL);
	while (str_to_copy[k] != '\0')
	{
		str[k] = str_to_copy[k];
		k++;
	}
	str[k] = '\0';
	return (str);
} */
