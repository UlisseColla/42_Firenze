/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:56 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/14 18:13:19 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/* Creazione pipe tra processi figli */
void	child_to_child(char *const *argv_path, int i, int pipe_cc[i][2])
{
	if (access(build_path(argv_path[0]), R_OK) != 0)
	{
		perror("Error reading file");
		exit(1);
	}
	wait(NULL); //Aspetta figlio precedente
	close(pipe_cc[i - 1][1]); /* chiudo write del pipe precedente */
	close(pipe_cc[i][0]); /* chiudo read del pipe appena creato */
	if (dup2(pipe_cc[i][0], 0) == -1 || dup2(pipe_cc[i][1], 1) == -1)
				perror("child to child");
	if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
			perror("execve");
}

int main(int argc, char **argv)
{
	int		n_pipe[argc - 4][2];
	int 	i;
	int 	infile;
	int 	outfile;
	pid_t 	child_pid[argc - 3];

	if (argc < 5)
		return (-1);

	i = 0;
	while (i < argc - 4) //creo i pipes che mi servono
	{
		pipe(n_pipe[i]);
		i++;
	}
	i = 0;
	while (i < argc - 3) //fork() per tante volte quante per n_pipe => argc - 3
	{
		child_pid[i] = fork();
		if (child_pid[i] == 0 && i == 0) //primo figlio legge da infile
		{
			printf("siamo nel primo figlio\n");
			infile = open("infile", O_RDONLY);
			if (infile == -1) 
			{
    			perror("Error opening infile");
    			exit(1);
			}
			close(n_pipe[i][0]); /* chiudo read del pipe <x> */
			
			printf("Child %d, PID:%d\n", i, getpid());

			close(n_pipe[i][1]); /* chiudo write del pipe <x> */
			pipex(infile, n_pipe[i], child_pid[i], ft_split(argv[i + 2], ' '));

			exit(0);
		}
		else if (child_pid[i] == 0 && i != 0)
		{
			printf("Siamo nel processo figlio con i: %d\n", i);
			
			// close(n_pipe[i - 1][1]); /* chiudo write del pipe precedente <x> */
			close(n_pipe[i][0]); /* chiudo read del pipe appena creato <y> */
			
			printf("Child %d, PID:%d\n", i, getpid());
			
			close(n_pipe[i][1]); /* chiudo write del pipe <y> */
			child_to_child(ft_split(argv[i + 2], ' '), i, n_pipe);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i < argc - 3)
    {
        waitpid(child_pid[i], NULL, 0);
		i++;
    }
	printf("Parent PID: %d, child PID %ls\n", getpid(), child_pid); //Parent attende i processi figlio e poi scrive su outfile
	i = 0;
	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile == -1) 
	{
		perror("Error opening outfile");
		exit(1);
	}
	pipex(outfile, n_pipe[i], child_pid[argc - 4], ft_split(argv[i + 2], ' '));
	i = 0;
	while (i < argc - 4)
	{
        close(n_pipe[i][0]);
        close(n_pipe[i][1]);
		i++;
    }
	return (0);
}
