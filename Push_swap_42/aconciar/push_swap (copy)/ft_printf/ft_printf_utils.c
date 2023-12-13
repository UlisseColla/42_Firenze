/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:13:27 by aconciar          #+#    #+#             */
/*   Updated: 2023/11/02 15:18:31 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	n_sp(int nbr, int len)
{
	int	i;

	if (nbr < 0)
		nbr *= -1;
	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= len;
	}
	return (i);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	nb;
	int	sp;

	len = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		ft_char('-');
		nb *= -1;
	}
	if (nb < len)
		ft_char(base[nb]);
	if (nb >= len)
	{
		ft_putnbr_base(nb / len, base);
		ft_putnbr_base(nb % len, base);
	}
	sp = n_sp(nbr, 16);
	if (nbr > 0)
		return (sp);
	else
		return (sp + 1);
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	unsigned int	nb;

	nb = nbr;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	else
	{
		if (nb <= 9)
			ft_char((nb + '0'));
		else
		{
			if (ft_strcmp(base, "0123456789abcdef") == 0)
				ft_char((nb - 10 + 'a'));
			else if (ft_strcmp(base, "0123456789ABCDEF") == 0)
				ft_char((nb - 10 + 'A'));
		}
	}
	return (0);
}
