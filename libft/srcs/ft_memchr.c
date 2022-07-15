/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:51:16 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/15 16:56:13 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	while (*str && *str != (unsigned char)ch && n)
	{
		str++;
		n--;
	}
	if (*str == (unsigned char)ch)
		return (str);
	else
		return (0);
}
