/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:22 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/07 14:27:02 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1999
# endif

char	*get_next_line(int fd);
char	*create_line(char *str);
char	*find_line(int fd, char **extra_char);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char a);
char	*ft_substr(char *str_to_search, char c_to_find);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *str_to_copy);

#endif