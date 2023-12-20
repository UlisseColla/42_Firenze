/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:57:09 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/19 20:02:43 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack)
{
	t_list	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sa\n");
}

void	swap_b(t_list **stack)
{
	t_list	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}