/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:23:39 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/17 15:45:22 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//buf_size is always bigger than or equal to 1

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;

	if (!str)
		return (0);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	if ((size_t)start > ft_strlen(str))
		ret[0] = 0;
	else
		ft_strlcpy(ret, str + start, len + 1);
	return (ret);
}
