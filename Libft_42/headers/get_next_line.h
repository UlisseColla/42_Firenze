/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:22 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/08 10:40:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*create_line(char *str);
char	*find_line(int fd, char **extra_char);
char	*save_rest(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, size_t k);
char	*ft_strchr(char *str, char a);
char	*ft_strdup(char *str);

#endif