/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:32:10 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/28 14:42:32 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main()
{
	const char *path = "/bin/ls";

	char *const argv[] = {"ls", "-l", "-a", NULL};

	char *const envp[] = {NULL};
	printf("Programm running\n");

    if (execve(path, argv, envp) == -1) {
        perror("execve");
    }

	printf("Fail execve\n");
}