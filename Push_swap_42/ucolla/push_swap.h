/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:39 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 17:37:46 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/* Operations */
void	push_a(t_list **stack, t_list **node);
void	push_b(t_list **stack, t_list **node);

void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

void	reverse_rotate_a(t_list **stack);
void	reverse_rotate_b(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);

/* Show stack */
void	show_stacks(t_list **stack_1, t_list **stack_2);
int		find_biggest(t_list *stack);

/* Sort three */
void	sort_three(t_list **stack);
int		find_smallest(t_list *stack);

/* Sort five */
void	sort_five(t_list **stack_a, t_list **stack_b);

#endif