#include <unistd.h>
#include <stdio.h>

int	main(void){
	int	max;

	max = sysconf(_SC_OPEN_MAX);
	printf("%d\n", max);
	return(0);
}
