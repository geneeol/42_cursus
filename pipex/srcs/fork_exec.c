/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:28:02 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/16 22:49:26 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include "../includes/pipex.h"
#include "../includes/ft_syscalls.h"
#include "../libft/includes/libft.h"

static int	open_outfile(t_proc *proc_info)
{
	int	file_fd;

	if (proc_info->limiter)
		file_fd = ft_open(proc_info->outfile, O_WRONLY | O_CREAT | O_APPEND);
	else
		file_fd = ft_open(proc_info->outfile, O_WRONLY | O_CREAT | O_TRUNC);
	return (file_fd);
}

static void	set_fd_stream(t_proc *proc_info)
{
	int	file_fd;

	if (proc_info->cur_cmd_idx == 0)
	{
		ft_close(proc_info->new_pipe[READ]);
		file_fd = ft_open(proc_info->infile, O_RDONLY);
		if (proc_info->limiter)
			if (unlink(proc_info->infile) < 0)
				ft_perror_exit("unlink failed");
		ft_dup2_close(file_fd, STDIN_FILENO);
		ft_dup2_close(proc_info->new_pipe[WRITE], STDOUT_FILENO);
	}
	else if (proc_info->cur_cmd_idx == proc_info->cmd_cnt - 1)
	{
		file_fd = open_outfile(proc_info);
		ft_dup2_close(proc_info->old_pipe[READ], STDIN_FILENO);
		ft_dup2_close(file_fd, STDOUT_FILENO);
	}
	else
	{
		ft_close(proc_info->new_pipe[READ]);
		ft_dup2_close(proc_info->old_pipe[READ], STDIN_FILENO);
		ft_dup2_close(proc_info->new_pipe[WRITE], STDOUT_FILENO);
	}
}

static void	parent_close_fd(t_proc *proc_info)
{
	if (proc_info->cur_cmd_idx == 0)
		ft_close(proc_info->new_pipe[WRITE]);
	else if (proc_info->cur_cmd_idx == proc_info->cmd_cnt - 1)
		ft_close(proc_info->old_pipe[READ]);
	else
	{
		ft_close(proc_info->old_pipe[READ]);
		ft_close(proc_info->new_pipe[WRITE]);
	}
}

static void	child_exec_cmd(t_proc *proc_info)
{
	const t_cmd	cur_cmd = proc_info->cmd_table[proc_info->cur_cmd_idx];

	set_fd_stream(proc_info);
	if (cur_cmd.is_executable)
		execve(cur_cmd.path, cur_cmd.argv, proc_info->envp);
	exit(EXIT_FAILURE);
}

//부모에서 생성한 파이프의 write부분을 다음 자식에게 넘겨주어야 함
//idx가 반복문 벗어난 이후 의미없는 값을 갖게되버림...
void	fork_exec(t_proc *proc_info)
{
	while (proc_info->cur_cmd_idx < proc_info->cmd_cnt)
	{
		printf("here\n");
		if (proc_info->cur_cmd_idx < proc_info->cmd_cnt - 1)
			ft_pipe(proc_info->new_pipe);
		proc_info->pid = fork();
		if (proc_info->pid < 0)
			ft_perror_exit("Failed to fork");
		else if (proc_info->pid > 0)
			parent_close_fd(proc_info);
		else
			child_exec_cmd(proc_info);
		ft_memcpy(proc_info->old_pipe, proc_info->new_pipe, 8);
		proc_info->cur_cmd_idx++;
	}
}
