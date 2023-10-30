/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:16:45 by ucolla            #+#    #+#             */
/*   Updated: 2023/10/30 15:54:17 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end_line(char	**str)
{
	size_t	i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
		return (1);
	return (0);
}

char	*build_line(int fd)
{
	char	*ret;
	char	*t1;

	ret = "";
	t1 = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	read(fd, t1, BUFFER_SIZE);
	t1[BUFFER_SIZE] = '\0';
	printf("|%s|\n", t1);
	while (find_end_line(&t1) < 1)
	{
		ret = ft_strjoin(ret, t1);
		read(fd, t1, BUFFER_SIZE);
		printf("|%s|\n", t1);
	}
	printf("\n");
	return (ret);
}

// char	*find_last_char(char *str, int fd)
// {
// 	char	*tmp;
// 	char	*ret;

// 	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (find_end_line(str) > 0)
// 	{
// 		read(fd, tmp, BUFFER_SIZE);
// 		tmp[BUFFER_SIZE] = '\0';
// 	}
// 	else
// 	{
// 		free(tmp);
// 		return (NULL);
// 	}
// 	while (tmp[i] != '\n' && tmp[i] != '\0')
	
// }

// void	get_next_line(int fd)
// {
// 	static char	*lines;
// 	char		*tmp;
// 	int 		i;

// 	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
// 	i = 0;
// 	if (fd < 0 || read(fd, lines, BUFFER_SIZE) < 0)
// 		return (NULL);
// 	read(fd, lines, BUFFER_SIZE);
// 	build_line(lines, fd);
// }


int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *ret = build_line(fd);
	printf("%s\n", ret);
}