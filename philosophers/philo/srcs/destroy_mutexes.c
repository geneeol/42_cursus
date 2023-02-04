/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:54:57 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/04 21:55:09 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

int	destroy_mutexes(t_args *args, int n_philo)
{
	int	i;

	pthread_mutex_destroy(&args->msg_lock);
	pthread_mutex_destroy(&args->common);
	i = 0;
	while (++i <= n_philo)
	{
		pthread_mutex_destroy(args->fork + i);
		pthread_mutex_destroy(args->personal + i);
	}
	return (CODE_ERROR_GENERIC);
}
