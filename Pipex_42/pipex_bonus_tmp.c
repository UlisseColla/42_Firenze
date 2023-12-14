/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_tmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:12:09 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/14 19:37:11 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av)
{
	int	pipes[ac - 4][2];
	int	infile = open("infile", O_RDONLY);
	int	outfile;
	int i;
	pid_t	f_value[ac - 3];

	av++;
	outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0666);
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
	i = -1;
	while (++i < ac - 3)
	{
		f_value[i] = fork();
		if (f_value[i] == 0 && i == 0)
		{
			char **argv_path = ft_split(av[i + 2], ' ');
			printf("Child process number: %d\n", i);
			
			close(pipes[i][0]); //chiudo read del pipe
			
			if (dup2(infile, 0) == -1) //reindirizza stdin a infile
				perror("Inifle");
			if (dup2(pipes[i][1], 1) == -1) //reindirizzo stdout a write del pipe
				perror("Stdout to write, first child");
			
			execve(build_path(argv_path[0]), argv_path, NULL);
		}
		else if (f_value[i] == 0 && i != 0)
		{
			char **argv_path = ft_split(av[i + 2], ' ');
			
			close(pipes[i][0]); //chiudo read del pipe corrente
			close(pipes[i - 1][1]); //chiudo write del pipe precedente
			
			if (dup2(pipes[i - 1][0], 0) == -1) //reindirizzo stdin al pipe precedente
				perror("Stdin to previous pipe");
			if (dup2(pipes[i][1], 1) == -1) //reindirizzo stdout al write del pipe attuale
				perror("Stdout to write, other child");
			
			execve(build_path(argv_path[0]), argv_path, NULL);
		}
		else if (f_value[i] != 0 && i == ac - 4) //Parent
		{
			char **argv_path = ft_split(av[i + 2], ' ');

			waitpid(f_value[ac - 4], NULL, 0);
			
			close(pipes[i - 1][1]); //chiudo write del pipe precedente

			if (dup2(pipes[i - 1][0], 0) == -1) //reindirizzo stdin al pipe precedente
				perror("Stdin parent");
			if (dup2(outfile, 1) == -1) //reindirizzo stdout al write del pipe attuale
				perror("Outfile");
				
			execve(build_path(argv_path[0]), argv_path, NULL);
			printf("Parent process e valore di i: %d\n", i);
		}
	}
	printf("Who prints this?\n");
}
