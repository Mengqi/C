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
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	printf("%d ", pop(s));
	printf("%d ", pop(s));
	push(s, 5);
	printf("%d ", pop(s));
	printf("%d ", pop(s));
	printf("%d ", pop(s));
	return 0;
}


