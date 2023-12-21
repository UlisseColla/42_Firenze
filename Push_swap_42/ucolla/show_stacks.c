/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:16:43 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/20 17:32:53 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_list *stack)
{
	int	max_value;
	int	current_value;
	
	max_value = INT_MIN;
	while (stack)
	{
		current_value = *(int *)(stack->content);
		if (current_value > max_value)
			max_value = current_value;
		stack = stack->next;
	}
	return (max_value);
}

int	format_n(int i)
{
	int n = 0;
	while (i > 0)
	{
		i /= 10;
		n++;
	}
	return (n);
}

void	show_stacks(t_list **stack_1, t_list **stack_2)
{
	int i = -1;
	int j = find_biggest(*stack_1);
	int l = find_biggest(*stack_2);
	
	while (*stack_1 || *stack_2)
	{	
		if (*stack_1 && *stack_2)
		{
			i = -1;
			ft_printf("| %d", (*(int *)((*stack_1)->content))); //stack a
			while (++i < format_n(j) - format_n(*(int *)((*stack_1)->content)))
				write(1, " ", 1);
			write(1, " |", 2);
			write(1, " -- ", 4);
			
			i = -1;
			ft_printf("| %d", (*(int *)((*stack_2)->content))); //stack b
			while (++i < format_n(l) - format_n(*(int *)((*stack_2)->content)))
				write(1, " ", 1);
			write(1, " |", 2);
			
			*stack_1 = (*stack_1)->next;
			*stack_2 = (*stack_2)->next;
		}
		else if (stack_1 && !stack_2)
		{
			i = -1;
			ft_printf("| %d", (*(int *)((*stack_1)->content)));
			while (++i < format_n(j) - format_n(*(int *)((*stack_1)->content)))
				write(1, " ", 1);
			write(1, " |", 2);
			write(1, " -- ", 4);
			
			i = -1;
			write(1, "| _", 3);
			while (++i < format_n(l) - 1)
				write(1, " ", 1);
			write(1, " |", 2);
			
			*stack_1 = (*stack_1)->next;
		}
		else if (!stack_1 && stack_2)
		{
			ft_printf("| _ | -- | %d |", *(int *)((*stack_2)->content));

			i = -1;
			ft_printf("| _", (*(int *)((*stack_1)->content)));
			while (++i < format_n(j) - 1)
				write(1, " ", 1);
			write(1, " |", 2);
			write(1, " -- ", 4);
			
			i = -1;
			ft_printf("| %d", *(int *)((*stack_2)->content));
			while (++i < format_n(l) - format_n(*(int *)((*stack_2)->content)))
				write(1, " ", 1);
			write(1, " |", 2);
			*stack_2 = (*stack_2)->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
