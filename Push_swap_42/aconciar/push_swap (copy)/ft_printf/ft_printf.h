/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:35:58 by aconciar          #+#    #+#             */
/*   Updated: 2023/11/02 14:26:04 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_char(char c);
int	ft_dec(int n);
int	ft_string(char *str);
int	n_sp(int nbr, int len);
int	ft_putnbr_base(int nbr, char *base);
int	ft_unsigned(unsigned int n);
int	ft_ptr_void(uint64_t ptr);
int	ft_putnbr_hex(unsigned int nbr, char *base);
int	ft_strcmp(const char *s1, const char *s2);

#endif