/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:50:11 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 00:44:56 by dahkang          ###   ########.fr       */
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


const char	**cmd_parser(int argc, char *argv[], char *const *envp);

/*
void	exec_first_cmd(t_proc *proc_info)
{
	const int		cmd_idx = proc_info->cmd_idx;	
	const t_cmd		cmd = proc_info->cmd_table[cmd_idx];
	int				fd_in;

	//만약 실패시 열어둔 파이프는 어떻게 되는가?
	//exit시 파이프
	fd_in = open(proc_info->file_name[0], O_RDONLY);
	if (fd_in < 0)
		ft_perror_exit("Failed to open infile");
	dup2(fd_in, STDIN_FILENO);
	dup2(proc_info->new_pipe[1], STDOUT_FILENO);
	close(fd_in);
	close(proc_info->new_pipe[1]);
	//close 필요성?
	if (cmd.is_executable)
		execve(cmd.cmd_paths, cmd.cmd_args, cmd.envp);
	exit(EXIT_FAILURE);
}

void	exec_last_cmd(t_proc *proc_info)
{
	const int		cmd_idx = proc_info->cmd_idx;	
	const t_cmd		cmd = proc_info->cmd_table[cmd_idx];
	int				fd_out;

	fd_out = open(proc_info->file_name[1], O_RDWR);
	if (fd_out < 0)
		ft_perror_exit("Failed to open outfile");
	dup2(proc_info->old_pipe[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(proc_info->old_pipe[0]);
	//close 필요성?
	//close에 대한 예외?
	//굳이 access함수를 쓰는 이유?
	if (cmd.is_executable)
		execve(cmd.cmd_paths, cmd.cmd_args, cmd.envp);
	exit(EXIT_FAILURE);
}

void	exec_middle_cmd(t_proc *proc_info)
{
	const int		cmd_idx = proc_info->cmd_idx;	
	const t_cmd		cmd = proc_info->cmd_table[cmd_idx];

	dup2(proc_info->old_pipe[0], STDIN_FILENO);
	dup2(proc_info->new_pipe[1], STDOUT_FILENO);
	close(proc_info->old_pipe[0]);
	close(proc_info->new_pipe[1]);
	if (cmd.is_executable)
		execve(cmd.cmd_paths, cmd.cmd_args, cmd.envp);
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_proc *proc_info, int argc)
{
	if (proc_info->cmd_idx == 1)
		exec_first_cmd(proc_info);
	else if (proc_info->cmd_idx == argc - 3)
		exec_last_cmd(proc_info);
	else
		exec_middle_cmd(proc_info);
}
*/

int	main(int argc, char *argv[], char *envp[])
{
	t_proc	*proc_info;

	if (argc < 5 || (!ft_strncmp("here_doc", argv[1], 9) && argc < 6))
		return (0);
	proc_info = init_info(argc, argv, envp);
	if (!proc_info)
		return (0);
	fork_exec(proc_info);
	wait_children(proc_info);
	return (0);
}
