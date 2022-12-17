/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:28:02 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/18 03:23:57 by dahkang          ###   ########.fr       */
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
		file_fd = open(proc_info->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		file_fd = open(proc_info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd < 0)
		ft_perror_exit("Failed to open file");
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

	//dprintf(2, "cmd_idx: %d\n", proc_info->cur_cmd_idx);
	set_fd_stream(proc_info);
	/*
	dprintf(2, "af stream\n");
	dprintf(2, "is_executable: %d\n", cur_cmd.is_executable);
	dprintf(2, "cur_cmd.path: %s\n", cur_cmd.path);
	int	i;

	i = -1;
	while (cur_cmd.argv[++i])
		dprintf(2, "cur_cmd.argv[%d]: %s\n", i, cur_cmd.argv[i]);
	dprintf(2, "envp: %p\n", proc_info->envp);
	i = -1;
	*/
	//while (proc_info->envp[++i])
//		dprintf(2, "envp[%d]: %s\n", i, proc_info->envp[i]);
	//if (cur_cmd.is_executable)
	execve(cur_cmd.path, cur_cmd.argv, proc_info->envp);
	//dprintf(2, "execve fail\n");
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cur_cmd.argv[0], 2);
	exit(127);
}

void	fork_exec(t_proc *proc_info)
{
	while (proc_info->cur_cmd_idx < proc_info->cmd_cnt)
	{
		//printf(">====parent 1=======<\n\n");
		if (proc_info->cur_cmd_idx < proc_info->cmd_cnt - 1)
			ft_pipe(proc_info->new_pipe);
		//printf("old_pipe[0]:%d, old_pipe[1]: %d\n", proc_info->old_pipe[0], proc_info->old_pipe[1]);
		//printf("new_pipe[0]:%d, new_pipe[1]: %d\n\n", proc_info->new_pipe[0], proc_info->new_pipe[1]);
		proc_info->pid = fork();
		if (proc_info->pid < 0)
			ft_perror_exit("Failed to fork");
		else if (proc_info->pid > 0)
		{
			//printf(">====parent 2=======<\n\n");
			parent_close_fd(proc_info);
		}
		else
		{
		//	printf(">======child=======<\n\n");
			child_exec_cmd(proc_info);
		}
		ft_memcpy(proc_info->old_pipe, proc_info->new_pipe, 8);
		proc_info->cur_cmd_idx++;
	}
}
