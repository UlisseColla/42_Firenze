/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:56 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/07 16:07:04 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*build_path(char *str)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * (ft_strlen(str) + 6));
	ft_strlcpy(path, "/bin/", 6);
	ft_strlcpy(path + 5, str, ft_strlen(str) + 1);
	return (path);
}

/* Funzione per lettura e scrittura da e su file */
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
			close(pipe_pc[0]);
			if (dup2(file, 0) == -1 || dup2(pipe_pc[1], 1) == -1)
				perror("parent dup2");
		}
		else
		{
			close(pipe_pc[1]);
			if (dup2(pipe_pc[0], 0) == -1 || dup2(file, 1) == -1)
				perror("child dup2");
		}
		close(file);
		if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
			perror("execve");
	}
}

/* Creazione pipe tra processi figli */
void	child_to_child(char *const *argv_path, int *pipe_cc[2], int i)
{
	if (access(build_path(argv_path[0]), R_OK) != 0)
	{
		perror("Error reading file");
		exit(1);
	}
	close(pipe_cc[i - 1][1]); /* chiudo write del pipe precedente */
	close(pipe_cc[i][0]); /* chiudo read del pipe appena creato */
	if (dup2(pipe_cc[i][0], 0) == -1 || dup2(pipe_cc[i][1], 1) == -1)
				perror("child to child");
	if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
			perror("execve");
}

int main(int argc, char **argv)
{
	int		*n_pipe[2]; 
	int 	i = 0;
	int 	infile;
	int 	outfile;
	pid_t 	child_pid;

	while (i < argc - 5)
	{
		pipe(n_pipe[i]);
		i++;
	}
	i = 0;
	while (i < 4) //fork() per tante volte quante per n_pipe => argc - 3
	{
		child_pid = fork();
		if (child_pid == 0 && i == 0) //primo figlio legge da infile
		{
			printf("siamo nel primo figlio\n");
			infile = open("infile", O_RDONLY);
			close(n_pipe[i][0]); /* chiudo read del pipe <x> */
			
			printf("Child %d, PID:%d\n", i, getpid());

			close(n_pipe[i][1]); /* chiudo write del pipe <x> */
			pipex(infile, n_pipe[i], child_pid, ft_split(argv[i + 2], ' '));

			exit(0);
		}
		else if (child_pid == 0 && i != 0)
		{
			printf("Siamo nel processo figlio con i: %d\n", i);
			
			close(n_pipe[i - 1][1]); /* chiudo write del pipe precedente <x> */
			close(n_pipe[i][0]); /* chiudo read del pipe appena creato <y> */
			
			printf("Child %d, PID:%d\n", i, getpid());
			
			close(n_pipe[i][1]); /* chiudo write del pipe <y> */
			child_to_child(ft_split(argv[i + 2], ' '), &n_pipe[2], i);
			exit(0);
		}
		i++; 
	}
	i = 0;
	while (i < 4)
    {
        waitpid(child_pid, NULL, 0);
		i++;
    }
	printf("Parent PID: %d, child PID %d\n", getpid(), child_pid); //Parent attende i processi figlio e poi scrive su outfile
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	i = 0;
	while (i < 3) 
	{
        close(n_pipe[i][0]);
        close(n_pipe[i][1]);
		i++;
    }
	pipex(outfile, n_pipe[i], child_pid, ft_split(argv[i + 2], ' '));
	return (0);
}
