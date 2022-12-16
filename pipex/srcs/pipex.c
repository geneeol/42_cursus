/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:50:11 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/16 22:34:40 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/ft_syscalls.h"
#include "../libft/includes/libft.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_proc	*proc_info;

	if (argc < 5 || (!ft_strncmp("here_doc", argv[1], 9) && argc < 6))
		return (0);
	proc_info = init_info(argc, argv, envp);
	if (!proc_info)
		return (0);
	fork_exec(proc_info);
	//무지성으로 while문 wait기다리면 안댐 ㅠ
	//wait_children(proc_info);
	return (0);
}
