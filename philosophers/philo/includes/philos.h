/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:10:43 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/03 03:03:10 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include "structures.h"

int			parse_input(t_rules *info, int argc, char **argv);
int			init(t_philo **philos, t_args *args, t_rules *rules);

int			pick_fork(t_philo *philo);
int			put_fork(t_philo *philo);
int			thinking(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);

int			create_threads(t_philo *philos, t_args *args);

int			get_cur_time(void);
int			get_elapsed_time(int start_time);
void		print_msg(char *str, int id, t_args *args);
void		ft_usleep(int time);

#endif

