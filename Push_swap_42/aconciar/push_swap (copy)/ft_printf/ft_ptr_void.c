/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:52 by aconciar          #+#    #+#             */
/*   Updated: 2023/11/02 15:27:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cont_ptr(uintptr_t nbr, int len)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= len;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_char((num + '0'));
		else
			ft_char((num - 10 + 'a'));
	}
}

int	ft_ptr_void(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		ft_string("(nil)");
		return (5);
	}
	i += write(1, "0x", 2);
	ft_put_ptr(ptr);
	i += cont_ptr(ptr, 16);
	return (i);
}
