/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:16:45 by ucolla            #+#    #+#             */
/*   Updated: 2023/10/28 16:15:29 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end_line(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n' || !str[i])
		return (1);
	return (0);
}

char	*find_line(char	*str)
{
	
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;
	
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[a] != '\0')
	{
		ret[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		ret[a] = s2[b];
		a++;
		b++;
	}
	ret[a] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	char		*tmp;
	int 		i;

	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	i = 0;
	if (fd < 0 || read(fd, lines, BUFFER_SIZE) < 0)
		return (NULL);
	read(fd, tmp, BUFFER_SIZE);
	tmp[BUFFER_SIZE] = '\0';
	// 1. Leggi fino a trovare \n o \0 e salva tutto di volta in volta in una stringa temp
	while (find_end_line(tmp))
	{
		read(fd, tmp, BUFFER_SIZE);
		
	}
	// 2. Assegna tmp a lines e ritorna lines.
}

int main()
{
	printf("%s\n", ft_strjoin("ciao", "come va"));
}