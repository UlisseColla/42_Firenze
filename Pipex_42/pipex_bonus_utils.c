/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:15:00 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/18 17:50:23 by ucolla           ###   ########.fr       */
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

char	*build_path(char *str)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * (ft_strlen(str) + 6));
	ft_strlcpy(path, "/usr/bin/", 10);
	ft_strlcpy(path + 9, str, ft_strlen(str) + 1);
	return (path);
}

void	pipex(int file, int *pipe_pc, pid_t child_pid, char *const *argv_path)
{
	if (access(build_path(argv_path[0]), R_OK) != 0)
	{
		perror("Error reading file");
		exit(1);
	}
	else
	{
		if (child_pid == 0)
		{
			close(pipe_pc[0]);
			if (dup2(file, 0) == -1 || dup2(pipe_pc[1], 1) == -1)
				perror("child dup2");
		}
		else
		{
			close(pipe_pc[1]);
			if (dup2(pipe_pc[0], 0) == -1 || dup2(file, 1) == -1)
				perror("parent dup2");
		}
		close(file);
		if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
			perror("execve");
	}
}

void close_pipes(int n, int index, int *pipes[2])
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ()
	}
}

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