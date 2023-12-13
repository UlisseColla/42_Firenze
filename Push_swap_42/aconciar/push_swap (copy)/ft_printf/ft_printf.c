/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:00:08 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/12 15:26:50 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	cont_hex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_type_var(va_list temp, va_list arg, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_char(va_arg(arg, int));
	if (c == 's')
		i += ft_string(va_arg(arg, char *));
	if (c == 'p')
		i += ft_ptr_void(va_arg(arg, uint64_t));
	if (c == 'i' || c == 'd')
		i += ft_dec(va_arg(arg, int));
	if (c == 'u')
		i += ft_unsigned(va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
	{
		i += cont_hex(va_arg(temp, unsigned int));
		if (c == 'x')
			i += ft_putnbr_hex(va_arg(arg, unsigned int), "0123456789abcdef");
		else
			i += ft_putnbr_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	}
	if (c == '%')
		i += ft_char('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	temp;
	va_list	arg;	
	int		len;
	int		i;

	va_start(temp, str);
	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type_var(temp, arg, str[i]);
		}
		else
			len += ft_char(str[i]);
		i++;
	}
	va_end(arg);
	va_end(temp);
	return (len);
}
