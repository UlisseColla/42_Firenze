/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:29:16 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/07 16:05:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

char	**ft_split_plus(char const *s, char c, char *file);
char	*build_path(char *str);
void	pipex(int file, int *pipe_pc, int child_pid, char *const *argv_path);
void	read_infile(int file, int *pipe_pc, char *const *argv_path);
void	child_to_child(char *const *argv_path, int *pipe_cc[2], int i);
char	*test(char *str);

#endif