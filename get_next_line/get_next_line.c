/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:05:41 by dahkang           #+#    #+#             */
/*   Updated: 2022/08/06 16:26:18 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//아직 fd에 대한 예외처리는 고려하지 않음.
//일단 수도 코드 작성

//buf_size만큼 읽지 않을 수도 있으므로 몇바이트 읽었는지 저장하는 변수도 따로 필요하다
char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	byte_read;

	//여기서 세가지 경우
	//정상적으로 읽거나, eof라 반복문을 나가거나, -1이거나
	while (byte_read = read(fd, buf, BUFFER_SIZE))
	{

		//realloc없이 동적할당을 딱 읽은만큼 해줘야함.
		if (byte_read < 0)
			return (0);
		else if (byte_read > 0)
		{
			if (ft_strchr(buf, '\n')) 
			//buf에 개행이 있는지 검사
			//만약 개행이 있다면 딱 개행까지만 ret에 연결후 ret리턴
			//개행이 없다면 buf전체를 ret에 연결
		}
		else
		{
			//buf 전체를 ret에 연결(개행없음)
			//ret를 리턴
		}
	}
}
