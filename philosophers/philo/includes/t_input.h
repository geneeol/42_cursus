/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_input.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:32:38 by dahkang           #+#    #+#             */
/*   Updated: 2023/01/28 20:34:53 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INPUT_H
# define T_INPUT_H

# include <unistd.h>

typedef struct s_input
{
	int			n_philo;
	useconds_t	time_die;		
	useconds_t	time_eat;		
	useconds_t	time_sleep;		
	int			option;
	int			n_must_eat;
}	t_input;

#endif