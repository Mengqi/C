/**
 * stack.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: A template of stack.
 *
 * Note: All functions assume the given stack is _not_ NULL.
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/* init_stack: initialize a new stack */
struct stack *init_stack(void)
{
	struct stack *s;

	s = (struct stack *) malloc(sizeof(struct stack));
	if (s == NULL)
		return NULL;
	s->top = 0;
	return s;
}

/* push: push one element into the stack */
int push(struct stack *s, data_type val)
{
	if (s->top == DEFAULT_STACK_SIZE - 1)	/* stack is full */
		return -1;
	s->v[s->top] = val;
	s->top++;
	return 0;
}

/* pop: pop one element from the stack */
data_type pop(struct stack *s)
{
	s->top--;
	return s->v[s->top];
}

/* stack_empty: return 1 if stack is empty, otherwise 0 */
int stack_empty(struct stack *s)
{
	return (s->top == 0) ? 1 : 0;
}

