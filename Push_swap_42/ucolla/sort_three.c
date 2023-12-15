/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:50:32 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/15 19:30:31 by ucolla           ###   ########.fr       */
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

void	sort_three(t_list *stack)
{
	t_list *tmp = NULL;
	
	if (*(int *)(stack->content) == find_biggest(stack)) //max all'inizio
	{
		if (*(int *)(stack->next->content) == find_smallest(stack))
			rotate(&stack);
		else
		{
			swap(&stack);
			reverse_rotate(&stack);
		}
		show_stacks(stack, tmp);
	}
	else if (*(int *)(stack->content) == find_smallest(stack)) //min all'inizio
	{
		if (*(int *)(stack->next->content) == find_biggest(stack))
		{
			reverse_rotate(&stack);
			swap(&stack);
		}
		show_stacks(stack, tmp);
	}
	else // middle all'inizio
	{
		if (*(int *)(stack->next->content) == find_biggest(stack))
			reverse_rotate(&stack);
		else
			swap(&stack);
		show_stacks(stack, tmp);
	}
}
