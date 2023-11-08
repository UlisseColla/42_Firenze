/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:01:08 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/08 10:51:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_line(int fd, char **extra_char)
{
	size_t	k;
	char	*tmp;

	k = 1;
	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (k > 0 && !ft_strchr(tmp, '\n'))
	{
		if (!*extra_char)
			*extra_char = ft_strdup("");
		k = read(fd, tmp, BUFFER_SIZE);
		*extra_char = ft_strjoin(*extra_char, tmp, k);
		if (k == 0 && ft_strlen(*extra_char) == 0)
		{
			free(*extra_char);
			*extra_char = NULL;
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (*extra_char);
}

char	*create_line(char *str)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	ret = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ret[i] = '\n';
	return (ret);
}

char	*save_rest(char *str)
{
	char	*rest;

	while (*str != '\n' && *str)
		str++;
	if (*str == '\n')
		str++;
	if (!*str)
		return (NULL);
	rest = ft_strdup(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*extra_char[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	tmp = find_line(fd, &extra_char[fd]);
	if (tmp == NULL)
		return (NULL);
	line = create_line(tmp);
	extra_char[fd] = save_rest(tmp);
	free(tmp);
	return (line);
}
/* int main()
{
	int fd = open("test.txt", O_RDONLY);
	int fd_1 = open("test_1.txt", O_RDONLY);
	int fd_2 = open("test_2.txt", O_RDONLY);

	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd_1)))
	{
		printf("%s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd_2)))
	{
		printf("%s\n", line);
		free(line);
	}
	line = get_next_line(fd);
	printf("fd: %s\n", line);

	free(line);
	line = get_next_line(fd_1);
	printf("fd_1: %s\n", line);

	free(line);
	line = get_next_line(fd_2);
	printf("fd_2: %s\n", line);

	free(line);
	line = get_next_line(fd);
	printf("fd: %s\n", line);

	free(line);
	line = get_next_line(fd_2);
	printf("fd_2: %s\n", line);

	free(line);
	line = get_next_line(fd_1);
	printf("fd_1: %s\n", line);
	
	free(line);
	line = get_next_line(fd_2);
	printf("fd_2: %s\n", line);

	free(line);
} */