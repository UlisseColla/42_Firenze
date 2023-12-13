/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:17:47 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/13 17:18:09 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
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
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	rotate(t_list **stack)
{
	t_list	*value;

	value = *stack;
	*stack = (*stack)->next;
	value->next = NULL;
	ft_lstadd_back(stack, value);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
}