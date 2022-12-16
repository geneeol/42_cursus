/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:25:48 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/16 23:02:35 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/includes/libft.h"

char	**get_envp_paths(char *envp[])
{
	int		i;

	i = -1;
	while (envp && envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
	}
	return (0);
}

static char	*join_path_cmd(char *path, char *cmd)
{
	char	*path_prefix;
	char	*whole_path;

	path_prefix = ft_strjoin(path, "/");
	whole_path = ft_strjoin(path_prefix, cmd);
	free(path_prefix);
	return (whole_path);
}

char	*find_cmd_path(char *cmd, char **envp_paths)
{
	char	*cmd_path;
	int		i;

	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = -1;
	while (envp_paths && envp_paths[++i])
	{
		cmd_path = join_path_cmd(envp_paths[i], cmd);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (0);
}
