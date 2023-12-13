/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:52:51 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 15:16:36 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	char	*buf;
	size_t	i;

	i = 0;
	buf = (char *) str;
	while (i < n)
	{
		buf[i] = '\0';
		i++;
	}
	return (str);
}
