#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*p1 = 0;
	char	*p2 = 0;
	char	p3[] = "Hello 42 World";

	//dst만 널이고 dstsize가 0일 때 세그폴트가 나지 않음
	printf("ret: %lu\n", strlcpy(p1, p3, 0));
	return (0);
}
