/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:26:03 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/18 05:04:47 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line_bonus.h"
#include "../includes/pipex.h"
#include "../includes/ft_syscalls.h"
#include "../includes/cmd_parser.h"

static void	free_strs(char *strs[])
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

//should check return value of gnl whether it is null or not.
//When stdin get C-d, gnl return null. it can cause seg-fault problem
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
		if (line && ft_strncmp(line, limiter, limiter_len) == 0
			&& line[limiter_len] == '\n')
			break ;
		if (line)
			write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	ft_close(fd);
}

static void	set_cmd_table(t_proc *proc_info, char *argv[], char **envp_paths)
{
	t_cmd	*cmd_table;
	int		i;

	cmd_table = proc_info->cmd_table;
	i = -1;
	while (++i < proc_info->cmd_cnt)
	{
		if (access(argv[i], X_OK) == 0)
		{
			cmd_table[i].argv = ft_malloc(sizeof(char *) * 2);
			cmd_table[i].argv[0] = ft_strdup(argv[i]);
			cmd_table[i].argv[1] = 0;
		}
		else
			cmd_table[i].argv = ft_split(argv[i], ' ');
		cmd_table[i].path = find_cmd_path(cmd_table[i].argv[0], envp_paths);
		cmd_table[i].is_executable = cmd_table[i].path != 0;
	}
}

static t_proc	*init_heredoc(int argc, char *argv[], char *envp[])
{
	char	**envp_paths;
	t_proc	*proc_info;

	envp_paths = get_envp_paths(envp);
	proc_info = (t_proc *)ft_malloc(sizeof(t_proc));
	proc_info->cmd_table = (t_cmd *)ft_malloc((argc - 3) * sizeof(t_cmd));
	proc_info->envp = envp;
	proc_info->cur_cmd_idx = 0;
	proc_info->cmd_cnt = argc - 4;
	proc_info->limiter = argv[2];
	proc_info->infile = ".here_doc_tmp";
	create_tmp_file(argv[2]);
	proc_info->outfile = argv[argc - 1];
	set_cmd_table(proc_info, argv + 3, envp_paths);
	free_strs(envp_paths);
	return (proc_info);
}

t_proc	*init_info(int argc, char *argv[], char *envp[])
{
	char	**envp_paths;
	t_proc	*proc_info;

	if (!ft_strncmp("here_doc", argv[1], 9))
		return (init_heredoc(argc, argv, envp));
	envp_paths = get_envp_paths(envp);
	proc_info = (t_proc *)ft_malloc(sizeof(t_proc));
	proc_info->cmd_table = (t_cmd *)ft_malloc((argc - 3) * sizeof(t_cmd));
	proc_info->envp = envp;
	proc_info->cur_cmd_idx = 0;
	proc_info->cmd_cnt = argc - 3;
	proc_info->limiter = 0;
	proc_info->infile = argv[1];
	proc_info->outfile = argv[argc - 1];
	set_cmd_table(proc_info, argv + 2, envp_paths);
	free_strs(envp_paths);
	return (proc_info);
}
