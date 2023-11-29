/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:36:39 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/28 15:18:40 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void)
{
	if (argc != 5)
		return (-1);

	char prova[100];

	int fd_p_c[2];
	int fd_c_p[2];

	if (pipe(fd_p_c) == -1 || pipe(fd_c_p) == -1) {
        perror("pipe");
    }
	
	pid_t child = fork();
	
	if (child == 0) //Processo child 
	{
		printf("CHILD\n");
		close(fd_p_c[1]); //chiudo write del parent
		close(fd_c_p[0]); //chiudo read dal parent

		int i = read(fd_p_c[0], prova, 4);
		if (i < 0)
			perror("read");
		char *b = ft_zero(prova);

		write(fd_c_p[1], b, ft_strlen(b));
		
		close(fd_p_c[0]);
		close(fd_c_p[1]);
	}
	else //Processo parent
	{
		printf("PARENT\n");
		close(fd_p_c[0]); //chiudo read dal child
		close(fd_c_p[1]); //chiudo write dal child

		char test[20];

		int j = write(fd_p_c[1], "ciao", 4);
		if (j < 0)
			perror("write");

		read(fd_c_p[0], test, 4);
		printf("Output del child => %s\n", test);

		close(fd_p_c[1]);
		close(fd_c_p[0]);
	}
}