/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:50:11 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/18 03:30:25 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/ft_syscalls.h"
#include "../libft/includes/libft.h"

static int	wait_children(t_proc *proc_info)
{
	int	i;
	int	status;
	int	exit_status;

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
	if (!proc_info)
		return (0);
	fork_exec(proc_info);
	//system("leaks pipex");
	return (wait_children(proc_info));
}
