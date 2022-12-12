/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:50:11 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/12 19:35:36 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../includes/structures.h"
#include "../libft/includes/libft.h"

void		ft_perror_exit(char *err_msg);
const char	**cmd_parser(int argc, char *argv[], char *const *envp);

void	exec_first_cmd(t_execs *cmd_info)
{
	const int		cmd_idx = cmd_info->cmd_idx;	
	const t_cmd		cmd = cmd_info->cmd_table[cmd_idx];
	int				fd_in;

	//만약 실패시 열어둔 파이프는 어떻게 되는가?
	//exit시 파이프
	fd_in = open(cmd_info->file_name[0], O_RDONLY);
	if (fd_in < 0)
		ft_perror_exit("Failed to open infile");
	dup2(fd_in, STDIN_FILENO);
	dup2(cmd_info->new_pipe[1], STDOUT_FILENO);
	close(fd_in);
	close(cmd_info->new_pipe[1]);
	//close 필요성?
	if (cmd.is_executable)
		execve(cmd.cmd_paths, cmd.cmd_args, cmd.envp);
	exit(EXIT_FAILURE);
}

void	exec_last_cmd(t_execs *cmd_info)
{
	const int		cmd_idx = cmd_info->cmd_idx;	
	const t_cmd		cmd = cmd_info->cmd_table[cmd_idx];
	int				fd_out;

	fd_out = open(cmd_info->file_name[1], O_RDWR);
	if (fd_out < 0)
		ft_perror_exit("Failed to open outfile");
	dup2(cmd_info->old_pipe[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(cmd_info->old_pipe[0]);
	//close 필요성?
	//close에 대한 예외?
	//굳이 access함수를 쓰는 이유?
	if (cmd.is_executable)
		execve(cmd.cmd_paths, cmd.cmd_args, cmd.envp);
	exit(EXIT_FAILURE);
}

void	exec_middle_cmd(t_execs *cmd_info)
{
	const int		cmd_idx = cmd_info->cmd_idx;	
	const t_cmd		cmd = cmd_info->cmd_table[cmd_idx];

	dup2(cmd_info->old_pipe[0], STDIN_FILENO);
	dup2(cmd_info->new_pipe[1], STDOUT_FILENO);
	close(cmd_info->old_pipe[0]);
	close(cmd_info->new_pipe[1]);
	if (cmd.is_executable)
		execve(cmd.cmd_paths, cmd.cmd_args, cmd.envp);
	exit(EXIT_FAILURE);
}

void	exec_cmd(t_execs *cmd_info, int argc)
{
	if (cmd_info->cmd_idx == 1)
		exec_first_cmd(cmd_info);
	else if (cmd_info->cmd_idx == argc - 3)
		exec_last_cmd(cmd_info);
	else
		exec_middle_cmd(cmd_info);
}

//close에 대한 분기

int	main(int argc, char *argv[], char *envp[])
{
	t_execs	cmd_info;

	if (argc < 5)
		return (0);
	init_info(&cmd_info, argc, argv, envp);
	while (cmd_info.cmd_idx < argc - 3)
	{
		if (pipe(cmd_info.new_pipe) < 0)
			ft_perror_exit("Failed to create pipe");
		cmd_info.pid = fork();
		if (cmd_info.pid < 0)
			ft_perror_exit("Failed to fork");
		else if (cmd_info.pid > 0)
		{
			close(cmd_info.new_pipe[0]);
			close(cmd_info.new_pipe[1]);
		}
		else
			exec_cmd(&cmd_info, argc);
		ft_memcpy(cmd_info.old_pipe, cmd_info.new_pipe, 8);
		cmd_info.cmd_idx++;
	}
	wait(0);
	return (0);
}
