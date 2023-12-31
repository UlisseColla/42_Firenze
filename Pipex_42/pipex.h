/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:29:16 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/05 15:37:46 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"

void	ft_free(char **arr);
char	*find_path(char **envp);
char	*build_cmd(char *cmd, char *envp);
void	pipex(char *cmd, char **envp);
int		file_opener(char *file, int i);
void	read_here_doc(char **argv, int fd);
void	main_here_doc(char **argv);
void	print_error(void);

#endif