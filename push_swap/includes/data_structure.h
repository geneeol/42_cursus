/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:14:18 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 15:30:54 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

# include <stdlib.h>
# include "structures.h"

t_node	*ft_creat_node(int data);
int		pop_front(t_stack *stk);
int		pop_rear(t_stack *stk);
t_bool	push_front(t_stack *stk, int data);
t_bool	push_rear(t_stack *stk, int data);
int		get_front(t_stack *stk);
int		get_rear(t_stack *stk);

t_stack	*init_stack(void);
t_info	*init_info(void);

void	free_deque(t_stack *st);
void	free_info(t_info *set);

void	print_op(t_info *set);

#endif
