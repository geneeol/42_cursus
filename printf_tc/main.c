#include "../ft_printf/ft_printf.h"
#include "../ft_printf/ft_printf.c"
#include <stdio.h>

int	main(void)
{
	char	*null_ptr;
	char	*str;

	null_ptr = 0;
	str = "I'm dahkang";
	
	printf(">========='c' specifier===========<\n");
	ft_printf("hello 42 world\n");
	printf("\n\n\n");
	printf("%d\n", ft_printf("hello 42 world\n"));
	printf("\n\n\n");
	printf("%d\n", ft_printf("hello %c world\n", 'I'));
	//컴파일 단계에서 에러를 띄우려면 특정 속성을 상속받아야 한다 (어셈블리) 허용함수가 아님
	printf("char: %c\n", "a");

	printf(">========='s' specifier===========<\n");
	printf("com null_ptr ret: %d\n", (printf("null ptr: %s\n", null_ptr)));
	printf("mine null_ptr ret: %d\n", (ft_printf("null ptr: %s\n", null_ptr)));
	printf("\n\n\n");
	printf("com str ret: %d\n", (printf("str: %s\n", str)));
	printf("mine str ret: %d\n",(ft_printf("str: %s\n", str)));
	printf("\n\n\n");
	printf("%d\n", printf("hello %c world, str: %s\n", 'I', str));
	printf("%d\n", ft_printf("hello %c world, str: %s\n", 'I', str));
	printf(">========='p' specifier===========<\n");
	printf("addr: %p\n", str);
	printf("null addr: %p\n", null_ptr);
	return (0);
}
