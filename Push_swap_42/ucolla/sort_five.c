/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:30:43 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/20 19:55:22 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int count;
	t_list *tmp;
	
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	//primo elemento di b vicino a bottom
	if (*(int *)(*stack_b)->content > (*(int *)(*stack_a)->next->content)) //pusha incima
	{

		if (*(int *)(*stack_b)->content > *(int *)(ft_lstlast(*stack_a))->content) //maggiore della coda
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else //minore della coda
		{
			reverse_rotate_a(stack_a);
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
			rotate_a(stack_a);
		}
	}
	else //primo elemento di b vicino a top
	{
		if (*(int *)(*stack_b)->content > (*(int *)(*stack_a)->content)) //maggiore della testa
		{
			push_a(stack_a, stack_b);
			swap_a(stack_a);
		}
		else //minore della testa
			push_a(stack_a, stack_b);
	}
	
	count = 0;
	tmp = *stack_a;
	while ((*(int *)(*stack_b)->content > *(int *)(tmp)->content) && tmp != NULL)
	{
		count++;
		tmp = tmp->next;
		if (tmp == NULL)
			break ;
	}
	printf("fine while\n");
	if (count == 0)
	{
		printf("valore count: %d\n", count);
		push_a(stack_a, stack_b);
	}
	else if (count == 1)
	{
		printf("valore count: %d\n", count);
		push_a(stack_a, stack_b);
		swap_a(stack_a);

	}
	else if (count == 2)
	{
		printf("valore count: %d\n", count);
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (count == 3)
	{
		printf("valore count: %d\n", count);
		reverse_rotate_a(stack_a);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (count == 4)
	{
		printf("valore count: %d\n", count);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
}

	// if ((*(int *)(*stack_b)->content > *(int *)(*stack_a)->content) < (*(int *)(*stack_b)->content - *(int *)(ft_lstlast(*stack_a))->content))
	// {
	// 	if (*(int *)(*stack_b)->content < *(int *)(*stack_a)->next->content)
	// 	{
	// 		push_a(stack_a, stack_b);
	// 		swap_a(stack_a);
	// 	}
	// 	else
	// 	{
	// 		rotate_a(stack_a);
	// 		rotate_a(stack_a);
	// 		push_a(stack_a, stack_b);
	// 		reverse_rotate_a(stack_a);
	// 		reverse_rotate_a(stack_a);
	// 	}
	// }