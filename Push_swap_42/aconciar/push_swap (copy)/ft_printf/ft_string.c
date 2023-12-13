/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:09:26 by aconciar          #+#    #+#             */
/*   Updated: 2023/11/02 14:52:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i += ft_char(str[i]);
	return (i);
}
