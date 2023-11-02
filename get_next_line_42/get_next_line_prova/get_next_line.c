/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:16:45 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/02 16:22:08 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_extra_char(char *str,  char **extra_char)
{
	size_t	j;

	j = 0;
	while (str[j] != '\0')
	{
		(*extra_char)[j] = str[j];
		j++;
	}
	return (*extra_char);
}

int	find_end_line(char *str, char **extra_char)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		// printf("i: %zu - str[i] = |%c|\n", i, str[i]);
		i++;
		if (str[i] == '\n')
		{
			i++;
			*extra_char = (char *)malloc(sizeof(char) * ft_strlen(str) - i);
			*extra_char = fill_extra_char(&str[i], extra_char);
			// printf("extra_char: %s\n", *extra_char);
			return (1);
		}
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
		// tmp[BUFFER_SIZE] = '\0';
	}
	else
	{
		tmp = *extra_char;
		printf("extra_char = %s\n", *extra_char);
	}
	while (find_end_line(tmp, extra_char) != 1) /* creazione linea da ritornare fino a \n */
	{
		ret = ft_strjoin(ret, tmp);
		read(fd, tmp, BUFFER_SIZE);
		if (read(fd, tmp, BUFFER_SIZE) == 0)
			break ;
		// printf("read = %zd\n", read(fd, tmp, BUFFER_SIZE));
		// printf("tmp nel ciclo while: %s|\n", tmp);
	}
	// printf("tmp PRIMA find_last_char: %s|\n", tmp);
	tmp = find_last_char(tmp);
	// printf("tmp DOPO find_last_char: %s|\n", tmp);
	ret = ft_strjoin(ret, tmp);
	return (ret);
}

char	*find_last_char(char *str)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 0;
	while (str[i] != '\n') /* && str[i] != '\0'
							con questa condizione riesco a stampare tutto correttamente
							solo se BUFFER_SIZE e' maggiore della lunghezza totale
							del file - insieme a CHECK in find_end_line */
	{
		// printf("i = %zu e str[i] = %c\n", i, str[i]);
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
	int i = 1;
	while (i < 7)
	{
		ret = get_next_line(fd);
		printf("chiamata numero %d di get_next_line: |%s|\n", i, ret);
		i++;
	}
}