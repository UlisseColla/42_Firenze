/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:19:08 by ucolla            #+#    #+#             */
/*   Updated: 2023/11/28 19:01:15 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*build_path(char *str)
{
	char	*path;
	
	path = (char *)malloc(sizeof(char) * (ft_strlen(str) + 6));
	ft_strlcpy(path, "/bin/", 6);
	ft_strlcpy(path + 5, str, ft_strlen(str) + 1);
	return (path);
}

int	main(int argc, char **argv)
{
	if (argc < 0)
		return (-1);

	char	*const *argv_path;
	char	*const *envp;
	char	*path;
	
	argv_path = ft_split(argv[2], ' ');
	envp = NULL;
	path = build_path(argv_path[0]);

	execve(path, argv_path, envp);
}