#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = 0;
	char	*s2 = 0;
	char	*s3 = "hello";
	char	*s4 = "42world";

	//dst가 널이고 src가 널포인터가 아니면서 dst_size가 0이면 세그폴트 발생 안함
	printf("ret: %lu\n", strlcat(s1, s3, 0));
	return (0);
}
