/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_get_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:22:08 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 11:22:13 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

//if st is an empty stack what happend?
//I can't tell if ret=-1 is real value or not.
//because it can be also from the err value
//so this function should be called when stack isn't empty
int	get_front(t_stack *st)
{
	return (st->front->data);
}

int	get_rear(t_stack *st)
{
	return (st->rear->data);
}
