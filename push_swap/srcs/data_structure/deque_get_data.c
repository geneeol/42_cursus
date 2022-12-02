/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:22:08 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 14:24:46 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data_structure.h"

//This function should be called when stack isn't empty
//if not seg_fault will occur
int	get_front(t_stack *st)
{
	return (st->front->data);
}

int	get_rear(t_stack *st)
{
	return (st->rear->data);
}
