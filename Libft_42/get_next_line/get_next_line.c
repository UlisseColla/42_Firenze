/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:19 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/08 10:52:19 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*extra_char = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	tmp = find_line(fd, &extra_char);
	if (tmp == NULL)
		return (NULL);
	line = create_line(tmp);
	extra_char = save_rest(tmp);
	free(tmp);
	return (line);
}

/* int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 1; 
	printf("CHIAMATA NUMERO %d di get_next_line: %s\n", i, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("CHIAMATA NUMERO %d di get_next_line: %s\n", i, line);
		i++;
	}
	free(line);
} */
