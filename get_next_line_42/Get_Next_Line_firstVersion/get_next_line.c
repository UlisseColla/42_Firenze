/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:54:48 by ucolla            #+#    #+#             */
/*   Updated: 2023/10/27 12:05:54 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	divisor(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*ret;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ret = (char *)malloc(sizeof(char));
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

static char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static t_list	*make_list(char *str, t_list *tmp, t_list **head, int i)
{
	while (str[i] != '\0' && i < BUFFER_SIZE)
	{
		tmp = ft_lstnew(ft_substr(str, i, divisor(str)));
		ft_lstadd_back(head, tmp);
		i += divisor(str) + 1;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static t_list		*head = NULL;
	t_list				*tmp;
	static char			*lines;
	char				*tmp_str;
	int					i;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &lines, 0) < 0)
		return (NULL);
	if (!lines)
	{
		lines = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read(fd, lines, BUFFER_SIZE);
		if (!lines)
		{
			free(lines);
			return (NULL);
		}
	}
	i = 0;
	tmp = make_list(lines, tmp, &head, i);
	tmp_str = ft_strdup(head->data);
	head = head->next;
	return (tmp_str);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	size_t i = 0;
	
	while (i < 4)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	
	return (0);
}