/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:55:06 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/19 20:02:15 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack)
{
	t_list	*value;
	t_list	*seclast_node;

	value = *stack;
	while (value->next)
	{
		if (value->next->next == NULL)
			seclast_node = value;
		value = value->next;
	}
	seclast_node->next = NULL;
	ft_lstadd_front(stack, value);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack)
{
	t_list	*value;
	t_list	*seclast_node;

	value = *stack;
	while (value->next)
	{
		if (value->next->next == NULL)
			seclast_node = value;
		value = value->next;
	}
	seclast_node->next = NULL;
	ft_lstadd_front(stack, value);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}