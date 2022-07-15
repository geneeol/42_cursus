/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:08:58 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/15 19:38:01 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Is it  the user's responsibility to pass the appropriate parameters?
//It seems that there may be a case of passing through the null character.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return (haystack);
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle && !ft_memcmp(haystack, needle, needle_len))
			return (haystack);
		haystack++;
		len--;
	}
	return (0);
}
