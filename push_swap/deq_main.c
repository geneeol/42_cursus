#include "deque.c"
#include <stdio.h>

int	main(void)
{
	t_stack	*stk;
	t_node	*curr;
	int	arr[10] = {5, 3, 2, 4, 8, 1, 11, 10, 4, 6};
	int	i;

	stk = init_stack();
	i = -1;
	while (++i < 10)
	{
		push_rear(stk, arr[i]);
		printf("stk->front: %d\n", stk->front->data);
		printf("stk->rear: %d\n", stk->rear->data);
	}
	curr = stk->front;
	printf("data: %d\n", stk->front->data);
	pop_front(stk);
	printf("data1: %d\n", stk->front->data);
	pop_front(stk);
	printf("data2: %d\n", stk->front->data);

	/*
	while (curr)
	{
		printf("data: %d\n", curr->data);
		curr = curr->next;
	}
	*/
	return (0);
}
