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

/* stack_push: push one element into the stack */
void stack_push(struct stack *s, data_type val)
{
	if (stack_full(s) == 1) {	/* stack already full */
		perror("Invalid push: Stack is full\n");
		exit(1);
	}
	s->v[s->top] = val;
	s->top++;
}

/* stack_pop: pop one element from the stack */
data_type stack_pop(struct stack *s)
{
	if (stack_empty(s) == 1) {	/* stack already empty */
		perror("Invalid pop: Stack is empty\n");
		exit(1);
	}
	s->top--;
	return s->v[s->top];
}

/* stack_empty: return 1 if stack is empty, otherwise 0 */
int stack_empty(struct stack *s)
{
	return (s->top == 0) ? 1 : 0;
}

/* stack_full: return 1 if stack is full, otherwise 0 */
int stack_full(struct stack *s)
{
	return (s->top == DEFAULT_STACK_SIZE - 1) ? 1 : 0;
}

/* free_stack: free the memory of the stack */
void free_stack(struct stack *s)
{
	free(s);
}

/* print_stack: print all the data in the stack */
void print_stack(struct stack *s)
{
	int i;

	if (stack_empty(s) == 1)
		printf("The stack is empty.\n");
	else {
		printf("The stack contents are:\n");
		for (i = 0; i <= s->top; i++)
			printf("%d. " PRINT_ARG "\n", i+1, s->v[i]);
	}
}
