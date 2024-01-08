/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:15:00 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/05 18:36:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(void)
{
	ft_putstr_fd("Incorrect number of arguments,\n", 2);
	ft_putstr_fd("or incorrect arguments's order\n\n", 2);
	ft_putstr_fd("Two possible ways to run the program:\n\n", 2);
	ft_putstr_fd("1. One or multiple pipes:\n", 2);
	ft_putstr_fd("./pipex [in_file] cmd1 cmd2 ... [out_file]\n\n", 2);
	ft_putstr_fd("2. here_doc type and two commands:\n", 2);
	ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 [out_file]\n\n", 2);
	exit(EXIT_FAILURE);
}

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (ft_strchr(envp[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	*build_cmd(char *cmd, char *envp)
{
	int		i;
	char	**paths;
	char	*base_path;
	char	**split_cmd;
	char	*cmd_to_ret;

	i = -1;
	paths = ft_split(envp, ':');
	split_cmd = ft_split(cmd, ' ');
	while (paths[++i])
	{
		base_path = ft_strjoin(paths[i], "/");
		cmd_to_ret = ft_strjoin(base_path, split_cmd[0]);
		free(base_path);
		if (access(cmd_to_ret, R_OK) == 0)
		{
			ft_free(split_cmd);
			ft_free(paths);
			return (cmd_to_ret);
		}
		free(cmd_to_ret);
	}
	ft_free(split_cmd);
	ft_free(paths);
	return (NULL);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	file_opener(char *file, int i)
{
	int	fd;

	fd = 3;
	if (i == 0)
		fd = open(file, O_RDONLY, 0666);
	else if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (i == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		perror("File opening fail");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
