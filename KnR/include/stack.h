/**
 * stack.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _STACK_H
#define _STACK_H

#define DEFAULT_STACK_SIZE 1024

typedef int data_type;	/* modify data type here */

struct stack {
	data_type v[DEFAULT_STACK_SIZE];
	int top;
};

/* function declaration */
struct stack *init_stack(void);
int push(struct stack *s, data_type val);
data_type pop(struct stack *s);
int stack_empty(struct stack *s);

#endif	/* _STACK_H */
