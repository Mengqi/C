/**
 * knr.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: The main function.
 */

#include <stdio.h>

#include "linked_list_test.h"
#include "stack.h"

int main(int argc, char *argv[])
{
	void stack_test(void);

	stack_test();
	return 0;
}

/* stack_test: test stack functions, data_type_s is int here */
void stack_test(void)
{
	struct stack *s;

	s = init_stack();
	print_stack(s);
	stack_push(s, 1);
	stack_push(s, 2);
	stack_push(s, 3);
	print_stack(s);
	stack_pop(s);
	stack_push(s, 4);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
	stack_pop(s);
	print_stack(s);
}
