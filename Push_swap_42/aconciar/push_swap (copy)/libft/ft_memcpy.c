/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:56:04 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 15:30:33 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*bufd;
	const char	*bufs;

	bufd = (char *) dest;
	bufs = (const char *) src;
	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		bufd[i] = bufs[i];
		i++;
	}
	return (dest);
}
