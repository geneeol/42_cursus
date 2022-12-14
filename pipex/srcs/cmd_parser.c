/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:25:48 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 03:41:28 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/includes/libft.h"

char	*find_cmd_path(char *cmd, char **paths)
{
	char	*cmd_path
	int		i;

	if (ft_strchr(cmd, '/') && !access(cmd, X_OK))
		return (cmd);
	i = -1;
	while (paths[++i])
	{
		ft_strjoin(paths, "/");
	}
}
