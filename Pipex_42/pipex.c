/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:19:08 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/29 18:09:34 by ucolla           ###   ########.fr       */
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

// argv_path = ft_split(argv[2], ' ');
// envp = NULL;
// path = build_path(argv_path[0]);

// execve(path, argv_path, envp);

int	main(int argc, char **argv)
{
	char	*const *argv_path;
	char	*const *envp;
	char	*path_cmd;
	int		tmp_file;
	
	if (argc != 5)
		return (-1);

	printf("Inizio programma\n");
	tmp_file = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	//child 
	if (fork() == 0)
	{
		printf("CHILD\n");
		int		outfile;
		//parametri per execve
		argv_path = ft_split_plus(argv[3], ' ', "tmp");
		envp = NULL;
		path_cmd = build_path(argv_path[0]);
		//apertura file
		outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		tmp_file = open("tmp", O_RDONLY);
		//duplica fd per outfile
		if (dup2(outfile, 1) == -1)
			perror("child dup2");
		close(outfile);
		// close(tmp_file);
		//execve
		if (execve(path_cmd, argv_path, envp) == -1)
			perror("execve");
	}
	else
	{
		printf("PARENT\n");
		int	infile;
		//parametri per execve
		argv_path = ft_split_plus(argv[2], ' ', argv[1]);
		envp = NULL;
		path_cmd = build_path(argv_path[0]);
		//apertura file
		infile = open("infile", O_RDONLY);
		if (infile < 0)
			perror("open");
		//duplica fd per reindirizzare output da stdout su tmp
		if (dup2(tmp_file, 1) == -1)
			perror("parent dup2");
		close(infile);
		close(tmp_file);
		//execve
		if (execve(path_cmd, argv_path, envp) == -1)
			perror("execve");
	}
}

// while (*argv_path)
// {
// 	printf("%s\n", *argv_path);
// 	argv_path++;
// }
	