/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:07:45 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 15:42:22 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	lend;
	size_t	a;
	size_t	lens;
	size_t	i;

	s = (char *)src;
	lend = ft_strlen(dst);
	lens = ft_strlen(s);
	a = 0;
	i = 0;
	if (size > lend)
		a = lens + lend;
	else
		a = lens + size;
	while (s[i] && (lend + 1) < size)
	{
		dst[lend] = s[i];
		lend++;
		i++;
	}
	dst[lend] = '\0';
	return (a);
}
