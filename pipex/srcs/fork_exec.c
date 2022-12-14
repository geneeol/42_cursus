/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:28:02 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 00:31:50 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "../includes/structures.h"
#include "../includes/ft_syscalls.h"
#include "../libft/includes/libft.h"

void	set_fd_stream(t_proc *proc_info)
{
	int	file_fd;

	if (proc_info->cur_cmd_idx == 0)
	{
		//히얼독 권한 설정
		ft_close(proc_info->new_pipe[READ]);
		file_fd = ft_open(proc_info->infile, O_RDONLY);
		ft_dup2_close(file_fd, STDIN_FILENO);
		ft_dup2_close(proc_info->new_pipe[WRITE], STDOUT_FILENO);
	}
	else if (proc_info->cur_cmd_idx == proc_info->cmd_cnt - 1)
	{
		//파일 권한설정에 대해
		file_fd = ft_open(proc_info->outfile, O_RDWR);
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

void	parent_close_fd(t_proc *proc_info)
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

void	child_exec_cmd(t_proc *proc_info)
{
	const t_cmd	cur_cmd = proc_info->cmd_table[proc_info->cur_cmd_idx];

	set_fd_stream(proc_info);
	if (cur_cmd.is_executable)
		execve(cur_cmd.cmd_paths, cur_cmd.cmd_args, proc_info->envp);
	exit(EXIT_FAILURE);
}

//부모에서 생성한 파이프의 write부분을 다음 자식에게 넘겨주어야 함
//문제는 
//idx가 반복문 벗어난 이후 의미없는 값을 갖게되버림...
void	fork_exec(t_proc *proc_info)
{
	while (proc_info->cur_cmd_idx < proc_info->cmd_cnt)
	{
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

