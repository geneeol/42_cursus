/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:17:55 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/10 17:23:22 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	char	*ret;

	ret = 0;
	while (*str)
	{
		if (*str == (char)ch)
			ret = str;
		str++;
	}
	if (*str == (char)ch)
		ret = str;
	return (ret);
}
