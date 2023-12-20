/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:17:47 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/19 20:02:28 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack)
{
	t_list	*value;

	value = *stack;
	*stack = (*stack)->next;
	value->next = NULL;
	ft_lstadd_back(stack, value);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack)
{
	t_list	*value;

	value = *stack;
	*stack = (*stack)->next;
	value->next = NULL;
	ft_lstadd_back(stack, value);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}