/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:54:57 by dahkang           #+#    #+#             */
/*   Updated: 2023/02/05 15:46:10 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

int	destroy_mutexes(t_shared *shared, int n_philo)
{
	int	i;

	pthread_mutex_destroy(&shared->common);
	i = 0;
	while (++i <= n_philo)
	{
		pthread_mutex_destroy(shared->fork + i);
		pthread_mutex_destroy(shared->personal + i);
	}
	return (CODE_ERROR_GENERIC);
}
