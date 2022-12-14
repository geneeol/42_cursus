/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:16 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/15 01:25:23 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//이거 필요한가?
# include <sys/_types/_pid_t.h>

# define WRITE 1
# define READ 0

typedef int	t_bool;

typedef struct s_cmd
{
	const char	*cmd_path;
	char *const	*cmd_args;
	t_bool		is_executable;
}	t_cmd;

typedef struct s_proc
{
	char *const	*envp;
	t_cmd		*cmd_table;
	int			cur_cmd_idx;
	int			cmd_cnt;
	char		*infile;
	char		*outfile;
	int			new_pipe[2];
	int			old_pipe[2];
	pid_t		pid;
}	t_proc;

#endif
