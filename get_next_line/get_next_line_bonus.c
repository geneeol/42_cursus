/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:05:41 by dahkang           #+#    #+#             */
/*   Updated: 2022/08/14 23:54:29 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_free(t_line *line)
{
	if (line->str)
		free(line->str);
	line->str = 0;
	line->len = 0;
	return (0);
}

static char	*line_join(t_line *line, char *buf)
{
	if (!(line->len))
	{
		line->len = gnl_strlen(buf);
		if (line->str)
			free(line->str);
		line->str = 0;
		return (gnl_strdup(buf));
	}
	else
		return (gnl_strjoin(line, buf));
	return (0);
}

static char	*nl_parse(t_line *line, char *buf, ssize_t buf_len)
{
	char	*ret;
	char	*left;
	size_t	offset;
	size_t	cut_off;

	offset = gnl_strchr(buf, '\n') - buf;
	cut_off = line->len - buf_len + offset;
	ret = gnl_substr(line, 0, cut_off + 1);
	if (!ret)
		return (ft_free(line));
	left = gnl_substr(line, cut_off + 1, line->len);
	if (!(left))
	{
		free(ret);
		ret = 0;
		return (ft_free(line));
	}
	free(line->str);
	line->str = left;
	line->len = gnl_strlen(left);
	return (ret);
}

char	*get_eof(t_line *line)
{
	char	*ret;

	ret = line->str;
	line->str = 0;
	line->len = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_line	line[OPEN_FD_MAX];
	char			buf[BUFFER_SIZE + 1];
	ssize_t			byte;

	if (fd < 0 || fd >= OPEN_FD_MAX || BUFFER_SIZE <= 0)
		return (0);
	byte = read(fd, buf, BUFFER_SIZE);
	while (byte)
	{
		if (byte < 0)
			return (ft_free(&line[fd]));
		buf[byte] = 0;
		line[fd].str = line_join(&line[fd], buf);
		if (!(line[fd].str))
			return (ft_free(&line[fd]));
		if (gnl_strchr(buf, '\n'))
			return (nl_parse(&line[fd], buf, byte));
		byte = read(fd, buf, BUFFER_SIZE);
	}
	return (get_eof(&line[fd]));
}
