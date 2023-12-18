/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_tmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:12:09 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/18 14:15:18 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av)
{
	int	pipes[ac - 4][2];
	int	infile = open("infile", O_RDONLY);
	int	outfile;
	int i;
	pid_t	f_value[ac - 4];

	outfile = open("outfile", O_WRONLY | O_CREAT , 0666);
	if (outfile == -1)
				perror("Opening outfile");
	
	if (ac < 5)
	{
		write(2, "Numero di parametri insufficiente\n", 34);
		return (-1);
	}
	i = -1;
	while (++i < ac - 4) //creazione array di pipe
		pipe(pipes[i]);
	i = 0;
	while (i < ac - 4)
	{
		f_value[i] = fork();
		printf("Ciclo numero: %d e valore di f_value: %d\n", i, f_value[i]);
		if (f_value[i] == 0 && i == 0) //first child
		{
			char **argv_path = ft_split(av[i + 2], ' ');
			printf("Child process number: %d\n", i);
			
			close(pipes[i][0]); //chiudo read del pipe
			
			if (dup2(infile, 0) == -1) //reindirizza stdin a infile
				perror("Inifle");
			
			if (dup2(pipes[i][1], 1) == -1) //reindirizzo stdout a write del pipe attuale
				perror("Stdout to write, first child");
			
			if (access(build_path(argv_path[0]), R_OK) != 0)
			{
				perror("Error reading file");
				exit(1);
			}
			close(pipes[i][1]); //chiudo write end del pipe attuale dopo reindirizzamento
			if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
				perror("execve");
		}
		else if (f_value[i] == 0 && i > 0) //all other children
		{
			printf("First child, f_value: %d\n", f_value[i - 1]);
			printf("Second child, f_value: %d\n", f_value[i]);
			
			char **argv_path = ft_split(av[i + 2], ' ');
			
   			// waitpid(f_value[i - 1], NULL, 0);
			
			close(pipes[i][0]); //chiudo read del pipe corrente
			close(pipes[i - 1][1]); //chiudo write del pipe precedente

			if (dup2(pipes[i - 1][0], 0) == -1) //reindirizzo stdin al pipe precedente
				perror("Stdin to previous pipe");
			close(pipes[i - 1][0]); //chiudo read del pipe precedente
			
			if (dup2(pipes[i][1], 1) == -1) //reindirizzo stdout al write del pipe attuale
				perror("Stdout to write, other child");
			close(pipes[i][1]); // close write end of the current pipe
			
			printf("Child number --> %d\n\n", i);
			
			if (access(build_path(argv_path[0]), R_OK) != 0)
			{
				perror("Error reading file");
				exit(1);
			}
			if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
				perror("execve");
		}
		else if (f_value[i] != 0 && i == ac - 5) //Parent
		{
			printf("Parent process e valore di i: %d\n", i);
			char **argv_path = ft_split(av[i + 3], ' ');
			
			close(pipes[i - 1][1]); //chiudo write del pipe precedente
			close(pipes[i - 1][0]); //chiudo read del pipe precedente
			
			if (dup2(pipes[i][0], 0) == -1) //reindirizzo stdin al pipe precedente
				perror("Stdin parent");
			close(pipes[i][0]); //chiudo read del pipe attuale

			if (dup2(outfile, 1) == -1) //reindirizzo stdout al write del pipe attuale
				perror("Outfile");
			close(pipes[i][1]);
			
			if (access(build_path(argv_path[0]), R_OK) != 0)
			{
				perror("Error reading file");
				exit(1);
			}
			close(infile);
			close(outfile);

			for (int j = 0; j < ac - 4; ++j) 
			{
   				waitpid(f_value[j], NULL, 0);
			}

			if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
				perror("execve");
		}
		i++;
	}
}
