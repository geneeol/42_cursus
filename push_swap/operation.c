#include "ft.h"

//1. 가독성을 위해 pop, push 연산 사용
//이 경우 malloc실패에 대한 별도의 분기처리가 필요함
//2. 새로운 동적할당 없이 기존 노드를 이용해서 재배열
//malloc실패애 대한 예외처리는 필요 없지만 코드가 지저분해짐
t_bool	swap(t_stack *stk)
{
	t_node	*left;
	t_node	*middle;
	t_node	*right;

	if (stk->size <= 1)
		return (FALSE);
	left = stk->front;
	middle = left->next;
	right = middle -> next;
	left->next = right;
	left->prev = middle;
	right->prev = left;
	middle->next = left;
	middle->prev = 0;
	return (TRUE);
}

t_bool swap_a(t_stack *stk_a)
{
	return (swap(stk_a));
}

t_bool swap_b(t_stack *stk_b)
{
	return (swap(stk_b));
}
