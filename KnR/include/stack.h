/**
 * stack.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _STACK_H
#define _STACK_H

#define DEFAULT_STACK_SIZE 1024

typedef int data_type;	/* modify data type here */

#define PRINT_ARG "%d"

struct stack {
	data_type v[DEFAULT_STACK_SIZE];
	int top;
};

/* function declaration */
struct stack *init_stack(void);
void stack_push(struct stack *s, data_type val);
data_type stack_pop(struct stack *s);
int stack_empty(struct stack *s);
int stack_full(struct stack *s);
void free_stack(struct stack *s);
void print_stack(struct stack *s);

#endif	/* _STACK_H */
