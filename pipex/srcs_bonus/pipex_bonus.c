/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:50:11 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/19 16:39:35 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include "../includes/ft_syscalls_bonus.h"
#include "../libft/includes/libft.h"

static int	wait_children(t_proc *proc_info)
{
	int	i;
	int	status;
	int	exit_status;

	exit_status = 1;
	i = -1;
	while (++i < proc_info->cmd_cnt)
	{
		if (proc_info->pid == wait(&status))
			exit_status = WEXITSTATUS(status);
	}
	return (exit_status);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_proc	*proc_info;

	if (argc < 5 || (!ft_strncmp("here_doc", argv[1], 9) && argc < 6))
		return (1);
	proc_info = init_info(argc, argv, envp);
	fork_exec(proc_info);
	return (wait_children(proc_info));
}
