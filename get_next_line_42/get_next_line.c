/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:54:48 by ucolla            #+#    #+#             */
/*   Updated: 2023/10/27 16:20:39 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*create_list(t_list *head, char *line_to_read, int fd)
{
	char	*str;
	int		k;
	int		i;
	t_list	*new_node;

	k = read(fd, line_to_read, BUFFER_SIZE);
	line_to_read[k] = '\0';
	i = 0;
	str = (char *)malloc(sizeof(char) * k);
	while () //cicla finche' non trova \n o \0
	{
		while (i < BUFFER_SIZE) //crea stringa e crea nuovo nodo
		{
			if (line_to_read[i] == '\n')
			{
				str[i] = '\n';
				str[i + 1] = '\0';
				new_node = ft_lstnew(str);
				ft_lstadd_back(&head, new_node);
				return (head);
			}
			str[i] = line_to_read[i];
			i++;
		}
		str[i] = '\0';
		new_node = ft_lstnew(str);
		ft_lstadd_back(&head, new_node);
	}
	return (head);
}

char	*get_next_line(int fd)
{
	static t_list		*head = NULL;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// 1. fine the line by reading BUFFER_SIZE until \n or \0 is found
		// 2. create a list by storing what read() reads at each time
	head = create_list(head, line, fd);
		
	// 3. create the line to return
	
	// 4. clear the list 
	return (0);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int i = 0;
	int k;
	char buf[1000];
	
	// printf("%s\n", get_next_line(fd));
	/* while (i < 4)
	{
		i++;
	} */
	while (i < 4)
	{
		k = read(fd, buf, BUFFER_SIZE);
		printf("%s ||\n", buf);
		++i;
	}
	
	return (0);
}