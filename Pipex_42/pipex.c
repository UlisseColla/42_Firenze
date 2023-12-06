/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:19:08 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/04 17:50:42 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*build_path(char *str)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * (ft_strlen(str) + 6));
	ft_strlcpy(path, "/bin/", 6);
	ft_strlcpy(path + 5, str, ft_strlen(str) + 1);
	return (path);
}

void	pipex(int file, int *pipe_pc, int child_pid, char *const *argv_path)
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
			close(pipe_pc[1]);
			if (dup2(pipe_pc[0], 0) == -1 || dup2(file, 1) == -1)
				perror("child dup2");
		}
		else
		{
			close(pipe_pc[0]);
			if (dup2(file, 0) == -1 || dup2(pipe_pc[1], 1) == -1)
				perror("parent dup2");
		}
		close(file);
		if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
			perror("execve");
	}
}

int	main(int argc, char **argv)
{
	char *const	*argv_path;
	int			pipe_parent_child[2];
	pid_t		child_pid;
	int			outfile;
	int			infile;

	if (argc != 5)
		return (-1);
	pipe(pipe_parent_child);
	child_pid = fork();
	if (child_pid == 0)
	{
		argv_path = ft_split(argv[3], ' ');
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (outfile < 0)
			perror("outfile");
		pipex(outfile, pipe_parent_child, child_pid, argv_path);
	}
	argv_path = ft_split(argv[2], ' ');
	infile = open("infile", O_RDONLY);
	if (infile < 0)
		perror("open");
	pipex(infile, pipe_parent_child, child_pid, argv_path);
}
