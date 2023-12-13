/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:42:14 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 17:02:25 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*buf1;
	const char	*buf2;
	size_t		i;

	i = 0;
	buf1 = (const char *) s1;
	buf2 = (const char *) s2;
	while (n--)
	{
		if (buf1[i] != buf2[i])
			return ((unsigned char)buf1[i] - (unsigned char)buf2[i]);
		i++;
	}
	return (0);
}
