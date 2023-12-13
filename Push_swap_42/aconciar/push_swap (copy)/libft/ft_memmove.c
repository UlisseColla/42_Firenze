/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:00:32 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/18 18:02:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*bufs;
	char		*bufd;
	size_t		i;

	if (!src)
		return (NULL);
	bufs = (const char *)src;
	bufd = (char *)dest;
	i = 0;
	if (bufd > bufs)
		while (n-- > 0)
			bufd[n] = bufs[n];
	else
	{
		while (i < n)
		{
			bufd[i] = bufs[i];
			i++;
		}
	}
	return (dest);
}
