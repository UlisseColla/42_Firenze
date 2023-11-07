/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:19 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/07 14:41:33 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*find_line(int fd, char **extra_char)
{
	size_t	k;
	char	*tmp;
	char	*buf;

	k = 1;
	while (k > 0)
	{
		if (!*extra_char)
			*extra_char = ft_strdup("");
		tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		k = read(fd, tmp, BUFFER_SIZE);
		buf = ft_strjoin(*extra_char, tmp);
		*extra_char = buf;
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n') || k == 0)
			break ;
	}
	// free(buf);
	// buf = NULL;
	return (buf);
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
	rest = ft_strdup(str);
	// free(str);
	// str = NULL;
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*extra_char;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 /* || read(fd, NULL, BUFFER_SIZE) < 0 */)
		return (NULL);
	tmp = find_line(fd, &extra_char);
	line = create_line(tmp);
	extra_char = save_rest(tmp);
	// free(line);
	free(tmp);
	tmp = NULL;
	return (line);
}

int main()
{
	int fd = open("test_1.txt", O_RDONLY);
	int i = 1;
	while (i <= 14)
	{
		printf("CHIAMATA NUMERO %d di get_next_line: %s\n", i, get_next_line(fd));
		i++;
	}
}
