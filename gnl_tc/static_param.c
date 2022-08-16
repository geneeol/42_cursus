#include <stdio.h>

void	func(int num)
{
	printf("func num addr: %p\n", &num);
	num++;
	printf("num: %d\n", num);
}

int	func2()
{
	static int n;

	printf("func2 n addr: %p\n", &n);
	func(n);
	return (n);
}

int	main(void)
{
	printf("ret: %d\n", func2());
	printf("ret: %d\n", func2());
	func(3);
	return (0);
}
