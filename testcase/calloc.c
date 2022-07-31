#include <stdlib.h>
#include <stdio.h>
#include "../Libft/libft.h"

int	main(void)
{
	void	*ptr;

	ptr = malloc(0);
	if (!ptr)
		printf("ptr is null\n");
	else
		printf("ptr is not null\n");
	printf("addr: %p\n", ptr);
	//calloc에 0,0 넣으면 해제 가능한 메모리 할당
	//malloc 0도 마찬가지네..
	printf("%d\n", *((char *)ptr));
	return (0);
}
