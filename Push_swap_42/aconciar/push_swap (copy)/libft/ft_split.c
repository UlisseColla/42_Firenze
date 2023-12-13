/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:36:17 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/18 14:34:35 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	n_parole(char const *s, char c)
{
	size_t	i;
	int		t;

	t = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && t == 0)
		{
			t = 1;
			i++;
		}
		else if (*s == c)
			t = 0;
		s++;
	}
	return (i);
}

static char	*word_dup(char const *str, char c)
{
	char	*new;
	size_t	i;

	i = 0;
	while (str[i] && !is_sep(str[i], c))
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;

	if (!(s))
		return (0);
	split = (char **) malloc (sizeof(char *) * (n_parole(s, c) + 1));
	if (!(split))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && !is_sep(*s, c))
		{
			split[i] = word_dup(s, c);
			i++;
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	split[i] = 0;
	return (split);
}
/*
int main (void)
{
	char	**s2;
	char	*s1 = "mi chiamo andrea";
	int	i = 0;

	s2 = ft_split(s1, ' ');
	while (s2[i])
	{
		printf ("%s\n", s2[i]);
		i++;
	}
	return (0);
}*/