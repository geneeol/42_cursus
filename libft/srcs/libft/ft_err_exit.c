/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:12:15 by dahkang           #+#    #+#             */
/*   Updated: 2022/12/02 15:14:34 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_err_exit(char *err_msg, int err_status)
{
	ft_putendl_fd("Error\n", 2);
	if (err_msg)
		ft_putendl_fd(err_msg, 2);
	exit(err_status);
}
