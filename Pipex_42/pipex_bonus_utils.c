/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:15:00 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/07 17:25:19 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*test(char *str)
{
	int i = 0;
	char	*c;
	if (!str || str == NULL || ft_strlen(str) == 0)
		printf("VALORE ASSENTE\n");
	c = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		c[i] = str[i] + 1;
		i++;
	}
	c[i] = '\0';
	return (c);
}

// int		ft_strlen(char *c)
// {
// 	int i = 0;
// 	while(c[i] != '\0')
// 		i++;
// 	return (i);
// }

// void	read_infile(int file, int *pipe_pc, char *const *argv_path)
// {
// 	if (access(build_path(argv_path[0]), R_OK) != 0)
// 	{
// 		perror("Error reading file");
// 		exit(1);
// 	}
// 	close(pipe_pc[0]);
// 	if (dup2(file, 0) == -1 || dup2(pipe_pc[1], 1) == -1)
// 				perror("parent dup2");
// 	if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
// 			perror("execve");	
// }