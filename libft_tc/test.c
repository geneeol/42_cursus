#include <stdio.h>
#include <string.h>

int main()
{
	char str[10] = "abcdef";
	char str2[10] = "abcdef";

	printf("%s", memcpy(str + 3, str, 5));
	printf("\n%s", memmove(str2 + 3, str2, 5));
	return (0);
}
/*
char	*str = "abcdefhhhh";
char	dst[100];

memcpy(str + 3, str, 5);
i
*/
