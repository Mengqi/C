/**
 * stack.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _STACK_H
#define _STACK_H

#define DEFAULT_STACK_SIZE 1024

typedef int data_type_s;	/* modify data type here */

#define PRINT_ARG_S "%d"	/* print argument of data_type_s */

struct stack_node {
        data_type_s data;
	struct stack_node *prev;
	struct stack_node *next;
};

struct stack {
	struct stack_node *head;
	struct stack_node *tail;
	int count;
};

/* function declaration */
struct stack *init_stack(void);
struct stack_node *init_stack_node(data_type_s d);
int stack_push(struct stack *s, data_type_s d);
data_type_s stack_pop(struct stack *s);
int stack_empty(struct stack *s);
void free_stack_node(struct stack_node *node);
void free_stack(struct stack *s);
void print_stack(struct stack *s);

#endif	/* _STACK_H */
