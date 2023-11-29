/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:32:10 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/29 16:21:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main()
{
	int file = open("infile", O_RDWR);
	if (file == -1)
		perror("open");
	
	const char *path = "/bin/grep";

	char *const argv[] = {"grep", "pipex", "infile", NULL};

	char *const envp[] = {NULL};
	printf("Programm running, fd per file: %d\n", file);

	dup2(2, file);
	dup2(1, file);
	
	if (execve(path, argv, envp) == -1)
		perror("execve");
	close(file);
}