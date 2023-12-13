/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:47:03 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 15:31:49 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*buf;
	size_t	i;

	i = 0;
	buf = (char *) str;
	while (i < n)
	{
		buf[i] = (char)c;
		i++;
	}
	return (str);
}
