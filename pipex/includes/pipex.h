/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:10:07 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/19 16:29:48 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "structures.h"

void	ft_perror_exit(char *err_msg);
t_proc	*init_info(int argc, char *argv[], char *envp[]);
void	fork_exec(t_proc *proc_info);

#endif
