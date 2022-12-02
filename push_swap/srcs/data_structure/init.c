/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:23:44 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 13:58:03 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../../includes/data_structure.h"

t_node	*ft_creat_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_err_exit(0, EXIT_FAILURE);
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	if (!ret)
		ft_err_exit(0, EXIT_FAILURE);
	ret->front = 0;
	ret->rear = 0;
	ret->size = 0;
	return (ret);
}

t_info	*init_info(void)
{
	t_info	*ret;

	ret = (t_info *)malloc(sizeof(t_info));
	if (!ret)
		ft_err_exit(0, EXIT_FAILURE);
	ret->st_a = init_stack();
	ret->st_b = init_stack();
	ret->op_queue = init_stack();
	return (ret);
}
