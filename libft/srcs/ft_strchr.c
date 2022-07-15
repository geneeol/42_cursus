/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:07:25 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/16 01:28:25 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Shoud I cast return type?
char	*ft_strchr(const char *str, int ch)
{
	while (*str && *str != (char)ch)
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	else
		return (0);
}
