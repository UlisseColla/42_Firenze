/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:19:21 by aconciar          #+#    #+#             */
/*   Updated: 2023/10/18 17:45:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
