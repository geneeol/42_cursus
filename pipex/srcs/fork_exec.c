/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:28:02 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/18 19:14:06 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//maybe it would be better to parse excution_info in this function
static void	child_exec_cmd(t_proc *proc_info)
{
	const t_cmd	cur_cmd = proc_info->cmd_table[proc_info->cur_cmd_idx];

	set_fd_stream(proc_info);
	execve(cur_cmd.path, cur_cmd.argv, proc_info->envp);
	if (access(cur_cmd.path, F_OK) != 0)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cur_cmd.argv[0], 2);
		exit(127);
	}
	else if (access(cur_cmd.path, X_OK) != 0)
	{
		ft_putstr_fd("Permission denied: ", 2);
		ft_putendl_fd(cur_cmd.argv[0], 2);
		exit(126);
	}
	else
		exit(EXIT_FAILURE);
}

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
