/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:16:45 by ucolla            #+#    #+#             */
/*   Updated: 2023/10/31 18:35:38 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end_line(char *str, char **extra_char)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		i++;
		*extra_char = (char *)malloc(sizeof(char) * ft_strlen(str) - i);
		j = 0;
		while (str[i] != '\0')
		{
			(*extra_char)[j] = str[i];
			i++;
			j++;
		}
		return (1);
	}
	return (0);
}

char	*build_line(int fd, char **extra_char)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!*extra_char)
	{
		read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
	}
	else
		tmp = ft_strjoin(*extra_char, tmp);
	while (find_end_line(tmp, extra_char) < 1) /* creazione linea da ritornare fino a \n */
	{
		ret = ft_strjoin(ret, tmp);
		read(fd, tmp, BUFFER_SIZE);
	}
	tmp = find_last_char(tmp); 	
	ret = ft_strjoin(ret, tmp);
	return (ret);
}

char	*find_last_char(char *str)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 0;
	while (str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\n';
	tmp[i++] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*extra_char;
	char		*tmp;
	
	if (fd < 0)
		return (NULL);
	tmp = build_line(fd, &extra_char);
	return (tmp);
}

int main()
{
	int fd = open("test_1.txt", O_RDONLY);
	char *ret;
	int i = 0;
	while (i < 8)
	{
		ret = get_next_line(fd);
		printf("get_next_line: |%s|\n", ret);
		i++;
	}
}