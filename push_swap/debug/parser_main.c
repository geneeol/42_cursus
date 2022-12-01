#include "ft.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_info	*set;
	t_node	*curr;

	set = input_parser(argc, argv);
	curr = set->st_a->front;
	printf("size: %lu\n", set->st_a->size);
	while (curr)
	{
		printf("data: %d\n", curr->data);
		curr = curr->next;
	}
	return (0);
}
