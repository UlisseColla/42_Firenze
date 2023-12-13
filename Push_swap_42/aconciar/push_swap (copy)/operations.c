/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:15:21 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/13 17:17:21 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack, t_list **node)
{
	t_list *tmp_node;

	tmp_node = (*node)->next;
	ft_lstadd_front(stack, *node);
	*node = tmp_node;
}

void	swap(t_list **stack)
{
	t_list	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap (stack_a);
	swap (stack_b);
}
