/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:26:03 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/12 20:07:25 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/structures.h"

//parsing 만들기..
void	init_info(t_execs *cmd_info, int argc, char *argv[], char *envp[])
{
	int	i;

	cmd_info->cmd_idx = 0;
	cmd_info->file_name[0] = argv[0];
	cmd_info->file_name[1] = argv[argc - 1];
	cmd_info->cmd_table = (t_cmd *)malloc((argc - 3) * sizeof(t_cmd));
	if (!cmd_info)
		ft_perror_exit("malloc failed");
	i = -1;
	while (++i < argc - 3)
	{
		cmd_info->cmd_table[i] 
	}
}
