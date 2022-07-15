/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:59:47 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/15 17:07:22 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (((unsigned char)s1)[i] == ((unsigned char)s2)[i] && i < n)
		i++;
	return (((unsigned char)s1)[i] - ((unsigned char)s2)[i]);
}
