/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:50:11 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/12 00:09:33 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

//생각보다 놈 맞추면서 짜기 어렵네.. 함수 어떻게 쪼갤지 고민할 것
int	main(int argc, char *argv[], char *envp[])
{
	int	pipe_fd[2];
	int	file_fd[2];
	int	i;
	int	pid;

	i = 1;
	while (i++ < argc - 1)
	{
		if (pipe(pipe_fd) < 0)
			ft_perror_exit("Failed to create pipe");
		pid = fork();
		if (pid < 0)
			ft_perror_exit("Failed to fork");
		else if (pid > 0)
		{
			close(pipe_fd[1]);
		}
		else
		{
		
		}
	}
}
