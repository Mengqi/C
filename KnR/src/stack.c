/**
 * stack.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: A template of stack, doubly linked list version.
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
	s->head = NULL;
	s->tail = NULL;
	s->count = 0;
	return s;
}

/* init_stack_node: initialize a new stack node with data */
struct stack_node *init_stack_node(data_type_s d)
{
	struct stack_node *p;

	p = (struct stack_node *) malloc(sizeof(struct stack_node));
	if (p == NULL)
		return NULL;
	p->data = d;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

/* stack_push: push one element into the stack */
int stack_push(struct stack *s, data_type_s d)
{
	struct stack_node *p;

	p = init_stack_node(d);
	if (p == NULL)
		return -1;
	if (s->head == NULL) {	/* if the stack is empty */
		s->head = p;
		s->tail = p;
		p->prev = NULL;	/* 1st node's prev is NULL */
	} else {
		s->tail->next = p;
		p->prev = s->tail;
		s->tail = p;
	}
	s->count++;
	return 0;
}

/* stack_pop: pop one element from the stack */
data_type_s stack_pop(struct stack *s)
{
	struct stack_node *temp;
	data_type_s d;

	if (stack_empty(s) == 1) {	/* stack is already empty */
		perror("Invalid pop: Stack is empty\n");
		exit(1);
	}
	if (s->head == s->tail)	/* only one node in the stack */
		s->head = NULL;

	temp = s->tail;
	s->tail = temp->prev;	/* if stack becomes empty, tail == NULL */
	if (s->tail != NULL)
		s->tail->next = NULL;
	d = temp->data;
	free_stack_node(temp);
	s->count--;

	return d;
}

/* stack_empty: return 1 if stack is empty, otherwise 0 */
int stack_empty(struct stack *s)
{
	return (s->count == 0) ? 1 : 0;
}

/* free_stack_node: free the memory of the given stack node */
void free_stack_node(struct stack_node *node)
{
	free(node);
}

/* free_stack: free the memory of the stack */
void free_stack(struct stack *s)
{
	struct stack_node *curr, *temp;

	curr = s->head;
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free_stack_node(temp);
	}
	free(s);
}

/* print_stack: print all the data in the stack */
void print_stack(struct stack *s)
{
	int i;
	struct stack_node *p;

	if (stack_empty(s) == 1)
		printf("The stack is empty.\n");
	else {
		i = 1;
		p = s->head;
		while (p != NULL) {
			printf("%d. " PRINT_ARG_S "\n", i++, p->data);
			p = p->next;
		}
	}
}
