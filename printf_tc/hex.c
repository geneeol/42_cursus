#include <stdio.h>

int	main(void)
{
	unsigned int	num;

	num = 4294967295;
	printf("hex 15: %x\n", 15);
	printf("hex -1: %x\n", -1);
	printf("hex int max: %x\n", 2147483647);
	printf("hex u_int max: %x\n", num);
	printf("-1?: %d\n", printf("hex over int: %x\n", 555555555555));
	return (0);
}

//9,223,372,036,854,775,807
//18,446,744,073,709,551,615
//4,294,967,295
