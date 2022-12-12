/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:16 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/12 19:44:41 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//이거 필요한가?
# include <sys/_types/_pid_t.h>

typedef int	t_bool;

typedef struct s_cmd
{
	const char	*cmd_paths;
	char *const	*cmd_args;
	char *const	*envp;
	t_bool		is_executable;
}	t_cmd;

typedef struct s_execution
{
	t_cmd	*cmd_table;
	int		cmd_idx;
	char	*file_name[2];
	int		new_pipe[2];
	int		old_pipe[2];
	pid_t	pid;
}	t_execs;

#endif
