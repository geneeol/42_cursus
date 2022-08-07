/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahkang <dahkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:05:41 by dahkang           #+#    #+#             */
/*   Updated: 2022/08/07 14:13:30 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//아직 fd에 대한 예외처리는 고려하지 않음.
//일단 수도 코드 작성
//
//
//정적변수에 대해 고민해야하는데 음.. 정적변수를 쓰는 이유는 반복문에서 gnl을 적용해서 읽기 위해서 같다

char	*get_next_line(int fd)
{
	static	*t_line[OPEN_MAX];
	char	buf[BUFFER_SIZE];
	ssize_t	byte_read;

	//여기서 세가지 경우
	//정상적으로 읽거나, eof라 반복문을 나가거나, -1이거나
	
	byte_read = read(fd, buf, BUFFER_SIZE);
	while (byte_read)
	{

		//읽다가 에러 발생시 동적할당을 해제해주고 널 리턴
		if (byte_read < 0)
		{
			ft_free(t_line[fd]);
			return (0);
		}
		if (ft_strchr(buf, '\n')) 
		{
			if (t_line[fd] -> line)
				nl_in_line(t_line[fd], buf, ft_strjoin);
			else
				nl_in_line(t_line[fd], buf, ft_strdup);
		}
		else
		{
			if (t_line[fd] -> line)
				nl_not_in_line(t_line[fd], 


			//맨 처음에는 strdup을 이용해 새로운 문자열 생성
			//이후엔 strjoin을 이용해 prefix를 free한 후 이어붙이기
			//
			//buf에 개행이 있는지 검사
			//만약 개행이 있다면 딱 개행까지만 ret에 연결후 ret리턴
			//개행 이후부터 마지막 문자까지 rest에 저장 (substr사용)
			//개행이 없다면 buf전체를 ret에 연결
	}
	//eof를 만났을 때 << 이 경우 read함수에 대한 테케작성 필요
	//일단 개행없이 buf 전체를 ret에 연결
	//ret를 리턴 (당연히 끝에 널 추가)

}
