#include "ft_strlen.c"
#include "../ft_printf/ft_printf.h"
#include "../ft_printf/ft_printf.c"
#include "../ft_printf/ft_printf_str.c"
#include "../ft_printf/ft_printf_numeric.c"
#include "../ft_printf/ft_printf_utils.c"
#include <stdio.h>

int	main(void)
{
	char	*null_ptr;
	char	*str;

	null_ptr = 0;
	str = "I'm dahkang";
	
	/*
	printf(">============'c' specifier===========<\n");
	ft_printf("hello 42 world\n");
	printf("\n\n\n");
	printf("ret1: %d\n", ft_printf("hello 42 world\n"));
	printf("\n\n\n");
	printf("ret2: %d\n", ft_printf("hello %c world\n", 'I'));
	//컴파일 단계에서 에러를 띄우려면 특정 속성을 상속받아야 한다 (어셈블리) 허용함수가 아님
	printf("char: %c\n", "a");
	printf(">============'s' specifier===========<\n");
	printf("com null_ptr ret: %d\n", (printf("null ptr: %s\n", null_ptr)));
	printf("mine null_ptr ret: %d\n", (ft_printf("null ptr: %s\n", null_ptr)));
	printf("\n\n\n");
	printf("com str ret: %d\n", (printf("str: %s\n", str)));
	printf("mine str ret: %d\n",(ft_printf("str: %s\n", str)));
	printf("\n\n\n");
	printf("%d\n", printf("hello %c world, str: %s\n", 'I', str));
	printf("%d\n", ft_printf("hello %c world, str: %s\n", 'I', str));
	printf(">==========='p' specifier===========<\n");
	printf("com ret: %d\n", printf("com addr: %p\n", str));
	printf("mine ret: %d\n", ft_printf("mine addr: %p\n", str));
	printf("com ret: %d\n", printf("com null addr: %p\n", null_ptr));
	printf("mine ret: %d\n", ft_printf("mine null addr: %p\n", null_ptr));
	printf(">==========='x', 'X' specifier===========<\n");
	unsigned int	num;

	num = 4294967295;
	printf("com ret: %d\n", printf("com hex 15: %x\n", 15));
	printf("mine ret: %d\n", ft_printf("mine hex 15: %x\n", 15));
	printf("com ret: %d\n", printf("com hex -1: %x\n", -1));
	printf("mine ret: %d\n", ft_printf("mine hex -1: %x\n", -1));
	printf("com ret: %d\n", printf("com hex int max: %x\n", 2147483647));
	printf("mine ret: %d\n", ft_printf("mine hex int max: %x\n", 2147483647));
	printf("com ret: %d\n", printf("com hex u_int max: %x\n", num));
	printf("mine ret: %d\n", ft_printf("mine hex u_int max: %x\n", num));
	*/
	printf("com -1?: %d\n", printf("hex over int: %x\n", 555555555555));
	ft_printf("mine -1?: %d\n", ft_printf("hex over int: %x\n", 555555555555));
	ft_printf("10: %d\n", 10);
	printf(">==========='d'specifier===========<\n");
	printf("mine ret: %d\n", ft_printf("-10: %d\n", -10));;
	return (0);
}
