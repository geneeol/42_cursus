/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:16 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/19 16:29:06 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

# include <sys/wait.h>

# define WRITE 1
# define READ 0

typedef struct s_cmd
{
	char	*path;
	char	**argv;
}	t_cmd;

typedef struct s_proc
{
	char *const	*envp;
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
