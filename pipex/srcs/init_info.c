/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:26:03 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 02:24:39 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/structures.h"
#include "../includes/ft_syscalls.h"
#include "../includes/cmd_parser.h"

//parsing 만들기..
t_proc	*init_info(int argc, char *argv[], char *envp[])
{
	char	**const paths = get_paths(envp);
	t_proc	*proc_info;
	t_cmd	*cmd_table;
	int	i;

	if (!ft_strncmp("here_doc", argv[1], 9))
		return (init_info_heredoc());
	proc_info = (t_proc *)ft_malloc(sizeof(t_proc));
	proc_info->cmd_table = (t_cmd *)ft_malloc((argc - 3) * sizeof(t_cmd));
	cmd_table = proc_info->cmd_table;
	proc_info->cur_cmd_idx = 0;
	proc_info->infile = argv[0];
	proc_info->outfile = argv[argc - 1];
	i = -1;
	while (++i < argc - 3)
	{
		cmd_table[i].cmd_args = ft_split(argv[i + 1], ' ');
		cmd_table[i].cmd_path = find_cmd_path(cmd_table[i].cmd_args[0], paths);
		cmd_table[i].is_executable = cmd_table[i].cmd_path != 0;
	}	
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (proc_info);
}
