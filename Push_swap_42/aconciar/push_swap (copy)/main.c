/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/13 17:20:58 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*num;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		return (0);
	while (argv[++i])
	{
		num = malloc(sizeof(int));
		*num = atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(num));
	}
	sorting(stack_a, stack_b);
	while (stack_a)
	{	
		ft_printf("%d\n", (*(int *)(stack_a->content)));
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	while (stack_b)
	{	
		ft_printf("%d\n", (*(int *)(stack_b->content)));
		stack_b = stack_b->next;
	}
	return (0);
}