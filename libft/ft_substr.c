/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:23:39 by dahkang           #+#    #+#             */
/*   Updated: 2022/07/16 20:46:58 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
