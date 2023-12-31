/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:34:26 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/28 15:39:22 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	l_dst;
	size_t	l_src;

	k = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size <= l_dst)
		return (l_src + size);
	while (l_dst + k < size - 1 && src[k] != '\0')
	{
		dst[l_dst + k] = src[k];
		k++;
	}
	if (l_dst + k < size)
		dst[l_dst + k] = '\0';
	return (l_dst + l_src);
}
