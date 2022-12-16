/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:26:03 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/16 23:12:02 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line_bonus.h"
#include "../includes/pipex.h"
#include "../includes/ft_syscalls.h"
#include "../includes/cmd_parser.h"

static void	free_strs(char *strs[])
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

//gnl should check whether return value is null or not.
//When stdin get C-d, gnl return null. But in that case here_doc is still alive.
static void	create_tmp_file(char *limiter)
{
	const int	limiter_len = ft_strlen(limiter);
	char		*line;
	int			fd;

	fd = open(".here_doc_tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		ft_perror_exit("EXCEPTION: Failed to create tmp_file");
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(0);
		if (line && ft_strncmp(line, limiter, limiter_len) != 0
			&& line[limiter_len] != '\n')
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	ft_close(fd);
}

static t_proc	*init_heredoc(int argc, char *argv[], char *envp[])
{
	char	**envp_paths;
	t_proc	*proc_info;
	t_cmd	*cmd_table;
	int		i;

	envp_paths = get_envp_paths(envp);
	proc_info = (t_proc *)ft_malloc(sizeof(t_proc));
	proc_info->cmd_table = (t_cmd *)ft_malloc((argc - 3) * sizeof(t_cmd));
	cmd_table = proc_info->cmd_table;
	proc_info->cur_cmd_idx = 0;
	proc_info->limiter = argv[2];
	proc_info->infile = ".here_doc_tmp";
	create_tmp_file(argv[2]);
	proc_info->outfile = argv[argc - 1];
	i = -1;
	while (++i < argc - 4)
	{
		cmd_table[i].argv = ft_split(argv[i + 3], ' ');
		cmd_table[i].path = find_cmd_path(cmd_table[i].argv[0], envp_paths);
		cmd_table[i].is_executable = cmd_table[i].path != 0;
	}	
	free_strs(envp_paths);
	return (proc_info);
}

t_proc	*init_info(int argc, char *argv[], char *envp[])
{
	char	**envp_paths;
	t_proc	*proc_info;
	t_cmd	*cmd_table;
	int		i;

	if (!ft_strncmp("here_doc", argv[1], 9))
		return (init_heredoc(argc, argv, envp));
	envp_paths = get_envp_paths(envp);
	proc_info = (t_proc *)ft_malloc(sizeof(t_proc));
	proc_info->cmd_table = (t_cmd *)ft_malloc((argc - 3) * sizeof(t_cmd));
	cmd_table = proc_info->cmd_table;
	proc_info->cur_cmd_idx = 0;
	proc_info->limiter = 0;
	proc_info->infile = argv[1];
	proc_info->outfile = argv[argc - 1];
	i = -1;
	while (++i < argc - 3)
	{
		cmd_table[i].argv = ft_split(argv[i + 2], ' ');
		cmd_table[i].path = find_cmd_path(cmd_table[i].argv[0], envp_paths);
		cmd_table[i].is_executable = cmd_table[i].path != 0;
	}	

	int j;
	i = -1;
	while (++i < argc - 3)
	{
		j = -1;
		while (cmd_table[i].argv[++j])
			printf("i_cmd: %d, argv[%d]: %s\n", i, j, cmd_table[i].argv[j]);
		printf("i_cmd: %d, %s\n",i ,cmd_table[i].path);
	}
	free_strs(envp_paths);
	return (proc_info);
}
