/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:41:49 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/05 18:43:40 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char *cmd, char **envp)
{
	char	*path;
	char	**split_cmd;

	path = build_cmd(cmd, find_path(envp));
	split_cmd = ft_split(cmd, ' ');
	if (access(path, R_OK) == -1)
	{
		ft_putstr_fd("Error while searching for the command\n", 2);
		ft_putstr_fd("It doesn't exist or there might be a typo\n", 2);
		exit(EXIT_FAILURE);
	}
	if (execve(path, split_cmd, NULL) == -1)
	{
		ft_free(split_cmd);
		free(path);
		perror("Execve");
	}
}

void	read_here_doc(char **argv, int fd)
{
	char	*buff;

	while (42)
	{
		buff = get_next_line(0);
		if (ft_strncmp(argv[2], buff, ft_strlen(argv[2])) == 0
			&& ft_strlen(buff) - 1 == ft_strlen(argv[2]))
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(buff, fd);
		free(buff);
	}
}

void	main_here_doc(char **argv)
{
	int		pipe_hd[2];
	int		child_hd;

	if (pipe(pipe_hd) == -1)
		exit (EXIT_FAILURE);
	child_hd = fork();
	if (child_hd == -1)
		exit (EXIT_FAILURE);
	if (child_hd == 0)
	{
		close(pipe_hd[0]);
		read_here_doc(argv, pipe_hd[1]);
	}
	else
	{
		close(pipe_hd[1]);
		if (dup2(pipe_hd[0], 0) == -1)
			perror("redirect here_doc parent");
		wait(NULL);
	}
}

void	pipex(char *cmd, char **envp)
{
	int		pipe_fd[2];
	pid_t	child_pid;

	if (pipe(pipe_fd) == -1)
		exit (EXIT_FAILURE);
	child_pid = fork();
	if (child_pid == -1)
		exit (EXIT_FAILURE);
	if (child_pid == 0)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], 1) == -1)
			perror("Redirect child");
		ft_execve(cmd, envp);
	}
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], 0) == -1)
			perror("Redirect parent");
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc != 6)
			print_error();
		i = 0;
		outfile = file_opener(argv[argc - 1], 2);
		main_here_doc(argv);
	}
	else
	{
		if (argc < 5)
			print_error();
		i = -1;
		infile = file_opener(argv[1], 0);
		outfile = file_opener(argv[argc - 1], 1);
		dup2(infile, 0);
	}
	while (++i < argc - 4)
		pipex(argv[i + 2], envp);
	dup2(outfile, 1);
	ft_execve(argv[argc - 2], envp);
}
