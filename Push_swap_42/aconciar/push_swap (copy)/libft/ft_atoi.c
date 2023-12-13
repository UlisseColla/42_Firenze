/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:51:01 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/17 18:03:08 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)

{
	int	sign;
	int	i;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * sign);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 0)
		printf("%d", ft_atoi(argv[1]));
	return (0);
}*/
