/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:12:56 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/05 18:00:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// char	*build_path(char *str)
// {
// 	char	*path;

// 	path = (char *)malloc(sizeof(char) * (ft_strlen(str) + 6));
// 	ft_strlcpy(path, "/bin/", 6);
// 	ft_strlcpy(path + 5, str, ft_strlen(str) + 1);
// 	return (path);
// }

/* Funzione per lettura e scrittua da e su file */
// void	pipex(int file, int *pipe_pc, int child_pid, char *const *argv_path)
// {
// 	if (access(build_path(argv_path[0]), R_OK) != 0)
// 	{
// 		perror("Error reading file");
// 		exit(1);
// 	}
// 	else
// 	{
// 		if (child_pid == 0)
// 		{
// 			close(pipe_pc[1]);
// 			if (dup2(pipe_pc[0], 0) == -1 || dup2(file, 1) == -1)
// 				perror("child dup2");
// 		}
// 		else
// 		{
// 			close(pipe_pc[0]);
// 			if (dup2(file, 0) == -1 || dup2(pipe_pc[1], 1) == -1)
// 				perror("parent dup2");
// 		}
// 		close(file);
// 		if (execve(build_path(argv_path[0]), argv_path, NULL) == -1)
// 			perror("execve");
// 	}
// }

/* Creazione pipe tra processi figli */
// void	child_to_child()
// {
	
// }

int		ft_strlen(char *c)
{
	int i = 0;
	while(c[i] != '\0')
		i++;
	return (i);
}

char	*test(char *str)
{
	int i = 0;
	char	*c;
	c = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		c[i] = str[i] + 1;
		i++;
	}
	c[i] = '\0';
	return (c);
}

int main(void)
{
	int		n_pipe[3][2]; //matrice di pipe per tutti i figli
	int i = 0;
	int j = 0;
	char a[5] = "abcd";
	pid_t child_pid;

	while (j < 3)
	{
		pipe(n_pipe[j]);
		j++;
	}
	
	while (i < 4) //fork() per tante volte quante per n_pipe => argc - 3
	{
		child_pid = fork();
		if (child_pid == 0 && i == 0)
		{
			printf("siamo nel primo figlio\n");
			char *b;
			
			close(n_pipe[i][0]); //chiudo read del pipe <x>
			b = test(a);
			
			printf("Child %d, PID:%d\n", i, getpid());

			write(1, b, 4);
			write(1, "\n", 1);

			close(n_pipe[i][1]); //chiudo write del pipe <x>
			free(b);
			wait(NULL);
			exit(0);
		}
		else if (child_pid == 0 && i != 0)
		{
			printf("Siamo nel processo figlio con i: %d\n", i);
			char *b;
			b = (char *)malloc(sizeof(char) * 5);
			
			close(n_pipe[i - 1][1]); //chiudo write del pipe precedente <x>
			close(n_pipe[i][0]); //chiudo read del pipe appena creato <y>
			
			read(n_pipe[i - 1][0], b, 4);
			
			char *c = test(b);
			printf("Variabile c: %s\n", c);
			write(n_pipe[i][1], c, 4);

			printf("Child %d, PID:%d\n", i, getpid());
			fflush(stdout);  // Flush the output buffer
			
			close(n_pipe[i][1]); //chiudo write del pipe <y>
			free(b);
			free(c);
			wait(NULL);
			exit(0);
		}
		i++; 
	}
	i = 0;
	printf("Parent PID: %d, child PID %d\n", getpid(), child_pid);

	for (i = 0; i < 3; i++) 
	{
        close(n_pipe[i][0]);
        close(n_pipe[i][1]);
    }

	waitpid(child_pid, NULL, 0);

	return (0);
}