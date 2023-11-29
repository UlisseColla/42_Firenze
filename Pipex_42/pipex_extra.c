/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:56 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/28 15:15:55 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void rotone(char *str)
{
	int i = 0;
	char c;
	while (str[i])
	{
		c = str[i] + 1;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

char *ft_zero(char *str)
{
	int i = 0;
	char *a = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		a[i] = 'A';
		i++;
	}
	a[i] = '\0';
	return (a);
}



