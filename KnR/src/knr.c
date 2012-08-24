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
#include "queue.h"

static void stack_test(void);
static void queue_test(void);

int main(int argc, char *argv[])
{
	queue_test();

	return 0;
}

/* stack_test: test stack functions, data_type_s is int here */
static void stack_test(void)
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

/* queue_test: test queue functions, data_type_s is int here */
static void queue_test(void)
{
	struct queue *q;

	q = init_queue();
	print_queue(q);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	print_queue(q);
	dequeue(q);
	enqueue(q, 4);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
	dequeue(q);
	print_queue(q);
}
