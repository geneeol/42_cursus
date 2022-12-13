/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:26:03 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/13 22:46:24 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/structures.h"

//parsing 만들기..
t_proc	*init_info(int argc, char *argv[], char *envp[])
{
	t_proc	*proc_info;
	int	i;

	proc_info = (t_proc *)malloc(sizeof(t_proc));
	if (!proc_info)
		return (0);
	proc_info->cmd_idx = 0;
	proc_info->file_name[0] = argv[0];
	proc_info->file_name[1] = argv[argc - 1];
	proc_info->cmd_table = (t_cmd *)malloc((argc - 3) * sizeof(t_cmd));
	if (!proc_info)
		ft_perror_exit("malloc failed");
	i = -1;
	while (++i < argc - 3)
	{
		proc_info->cmd_table[i] 
	}	
}
