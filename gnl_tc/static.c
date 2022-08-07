#include <stdio.h>
#include <string.h>

char	*s = "hi";

typedef struct s_line	
{
	int	a;
	int	b;
} t_line;

typedef struct s_str
{
	char	*a;
	char	*b;
} t_str;

void	func(void)
{
	static	t_line var = {10, 20};
	printf("a: %d, b: %d\n", var.a, var.b);
	var.a += 1;
	var.b += 2;
}

void	func2(void)
{
	static	t_str var;
	printf("a: %p, b: %p\n", var.a, var.b);
	var.a = s;
}


int	main(void)
{
	func();
	func();
	func();
	func2();
	func2();
	func2();
	return (0);
}
