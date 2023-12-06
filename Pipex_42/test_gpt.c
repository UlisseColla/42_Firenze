/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:20:22 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/04 18:56:29 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// int main() {
//     int i = 0;

//     while (i < 5) {
//         pid_t child_pid = fork();

//         if (child_pid == -1) {
//             perror("fork");
//             return 1;
//         } else if (child_pid == 0) {
//             // This is the child process
//             printf("Child process with PID %d\n", getpid());
//             // Perform child process tasks...
//             _exit(0);  // Terminate the child process
//         } else {
//             // This is the parent process
//             printf("Parent process with PID %d created child with PID %d\n", getpid(), child_pid);
//         }

//         i++;
//     }

//     // Continue with the parent process tasks...

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // List of commands to execute
    char *commands[] = {
        "/bin/ls",
        "/bin/pwd",
        "/bin/echo",
        NULL
    };

    // Iterate over commands
    for (int i = 0; commands[i] != NULL; i++) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            return 1;
        } else if (child_pid == 0) {
            // This is the child process

            // Replace the child process with a new program
            if (execve(commands[i], &commands[i], NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }

            // This code is only reached if execve fails
            exit(EXIT_FAILURE);
        } else {
            // This is the parent process
            printf("Parent PID: %d, Child PID: %d\n", getpid(), child_pid);
        }
    }

    // Wait for all child processes to finish
    for (long unsigned int i = 0; i < sizeof(commands) / sizeof(commands[0]) - 1; i++) {
        int status;
        wait(&status);
        printf("Child process %ld terminated with status %d\n", i, status);
    }

    return 0;
}