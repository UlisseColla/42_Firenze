/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:58:41 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/19 18:03:00 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	n_sp(int nbr)
{
	size_t	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*temp(char *str, size_t sp, long int nb)
{
	while (sp--)
	{
		*(str + sp) = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

char	*zero(void)
{
	char	*str;

	str = ft_calloc(1, 2);
	*(str + 0) = 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	size_t		sp;

	nb = n;
	sp = n_sp(n);
	if (n < 0)
	{
		sp++;
		nb *= -1;
	}
	str = (char *)malloc(sizeof(char) * (sp + 1));
	if (n == 0)
	{
		str = zero();
		return (str);
	}
	if (str == NULL)
		return (NULL);
	*(str + (sp)) = '\0';
	str = temp(str, sp, nb);
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-10));
	return (0);
}*/
