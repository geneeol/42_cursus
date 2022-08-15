/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:05:50 by dahkang           #+#    #+#             */
/*   Updated: 2022/08/15 16:51:27 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//만약... byte 굉장히 크면?
//1. ssize_t의 max면 +1 할 때 터짐
//2. ssize_t의 범위를 buffer_size가 넘어버리면 read 리턴값이 어케대지?
//
#include "get_next_line.h"

/*
char	*gnl_strchr(const char *str, int ch)
{
	while (*str && *str != (char)ch)
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	else
		return (0);
}
*/

ssize_t	gnl_get_idx(char *str, char ch)
{
	ssize_t	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == ch)
			return (i);
	return (-1);
}

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strdup(const char *str)
{
	char	*ret;
	size_t	size;
	size_t	i;

	i = 0;
	size = gnl_strlen(str) + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (0);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*gnl_substr(t_line *line, size_t start, size_t len)
{
	char	*ret;
	size_t	size;
	size_t	i;

	i = 0;
	if (start >= line->len)
		return (gnl_strdup(""));
	if (line->len - start >= len)
		size = len + 1;
	else
		size = line->len - start + 1;
	ret = (char *)malloc(sizeof(char) * (size));
	if (!ret)
		return (0);
	while (i < len && (line->str)[start + i])
	{
		ret[i] = (line->str)[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*gnl_strjoin(t_line *line, char *buf)
{
	char	*ret;
	size_t	size;

	size = line->len + gnl_strlen(buf) + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
	{
		free(line->str);
		line->str = 0;
		return (0);
	}
	while (*(line->str))
		*ret++ = *((line->str)++);
	line->str -= line->len;
	free(line->str);
	line->str = 0;
	while (*buf)
		*ret++ = *buf++;
	*ret = '\0';
	ret -= size - 1;
	line->len = size - 1;
	return (ret);
}
