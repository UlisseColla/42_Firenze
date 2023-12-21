/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:32 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/20 19:36:27 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *stack)
{
	int	min_value;
	int	current_value;
	
	min_value = INT_MAX;
	while (stack)
	{
		current_value = *(int *)(stack->content);
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
	}
	return (min_value);
}

void	sort_three(t_list **stack)
{
	// t_list *tmp = NULL;
	
	if (*(int *)((*stack)->content) == find_biggest(*stack)) //max all'inizio
	{
		if (*(int *)((*stack)->next->content) == find_smallest(*stack))
			rotate_a(stack);
		else
		{
			swap_a(stack);
			reverse_rotate_a(stack);
		}
	}
	else if (*(int *)((*stack)->content) == find_smallest(*stack)) //min all'inizio
	{
		if (*(int *)((*stack)->next->content) == find_biggest(*stack))
		{
			reverse_rotate_a(stack);
			swap_a(stack);
		}
	}
	else // middle all'inizio
	{
		if (*(int *)((*stack)->next->content) == find_biggest(*stack))
			reverse_rotate_a(stack);
		else
			swap_a(stack);
	}
}
