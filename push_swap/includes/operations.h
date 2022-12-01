/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:09:02 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/01 19:11:18 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "structures.h" 

t_bool	swap(t_stack *stk);
t_bool	sa(t_info *set);
t_bool	sb(t_info *set);
t_bool	ss(t_info *set);
t_bool	push(t_stack *stk1, t_stack *stk2);
t_bool	pa(t_info *set);
t_bool	pb(t_info *set);
t_bool	rotate(t_stack *stk);
t_bool	ra(t_info *set);
t_bool	rb(t_info *set);
t_bool	rr(t_info *set);
t_bool	reverse_rotate(t_stack *stk);
t_bool	rra(t_info *set);
t_bool	rrb(t_info *set);
t_bool	rrr(t_info *set);

#endif
