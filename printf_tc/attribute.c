#include <stdio.h>
#include <stdarg.h>

int g_debug_level = 0;

extern void daprintf(int, char *, ...);
__attribute__ ((format (printf, 2, 3)));


void daprintf(int error_level, char *fmt, ...)
{

	va_list ap;

	va_start(ap, fmt);
	if (error_level >= g_debug_level)
		vfprintf(stderr, fmt, ap);
	va_end(ap);
}


// 2번째가 format string, 3번째가 가변 파라메타의 위치이다.

void foo()
{

	int local_variable;

	local_variable = 1;
	daprintf(0, "local_variable = %sn", local_variable);

}

int	main(void)
{
	foo();
	return (0);
}
