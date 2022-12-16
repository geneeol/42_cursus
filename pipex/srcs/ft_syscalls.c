/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscalls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:48:07 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/16 22:33:30 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/pipex.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_perror_exit("malloc failed");
	return (ret);
}

void	ft_pipe(int fd[2])
{
	if (pipe(fd) < 0)
		ft_perror_exit("Failed to create pipe");
}

int	ft_open(const char *path, int oflag)
{
	int	fd;

	fd = open(path, oflag);
	if (fd < 0)
		ft_perror_exit("Failed to open file");
	return (fd);
}

void	ft_close(int fd)
{
	if (close(fd) < 0)
		ft_perror_exit("Failed to close file");
}

void	ft_dup2_close(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
		ft_perror_exit("Failed to dup2");
	ft_close(fd1);
}
