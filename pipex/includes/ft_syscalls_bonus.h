/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscalls_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:25:04 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/16 21:12:03 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYSCALLS_BONUS_H
# define FT_SYSCALLS_BONUS_H

# include <stddef.h>

void	*ft_malloc(size_t size);
int		ft_pipe(int fd[2]);
int		ft_open(const char *path, int oflag);
void	ft_close(int fd);
void	ft_dup2_close(int fd1, int fd2);

#endif
