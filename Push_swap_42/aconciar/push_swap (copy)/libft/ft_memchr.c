/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:37:39 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 15:28:56 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*buf;
	char	character;

	buf = (char *)s;
	character = (char)c;
	i = 0;
	while (i < n)
	{
		if (*buf == character)
		{
			return (buf);
		}
		buf++;
		i++;
	}
	return (NULL);
}
