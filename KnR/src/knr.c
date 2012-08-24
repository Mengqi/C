/**
 * knr.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: The main function.
 */

#include <stdio.h>

#include "stack.h"

int main(int argc, char *argv[])
{
	struct stack *s;

	s = init_stack();
	stack_push(s, 1);
	stack_push(s, 2);
	stack_push(s, 3);
	printf(PRINT_ARG "\n", stack_pop(s));
	stack_push(s, 4);
	printf(PRINT_ARG "\n", stack_pop(s));
	stack_push(s,5);
	print_stack(s);

	return 0;
}


