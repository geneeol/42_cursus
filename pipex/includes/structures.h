/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:16 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/17 20:14:33 by dahkang          ###   ########.fr       */
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
	const char	*path;
	char *const	*argv;
	t_bool		is_executable;
}	t_cmd;

typedef struct s_proc
{
	char *const	*envp;
	char		**envp_paths;
	t_cmd		*cmd_table;
	int			cur_cmd_idx;
	int			cmd_cnt;
	char		*limiter;
	char		*infile;
	char		*outfile;
	int			new_pipe[2];
	int			old_pipe[2];
	pid_t		pid;
	int			exit_status;
}	t_proc;

#endif
