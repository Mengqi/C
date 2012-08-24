/**
 * queue.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: A template of queue, linked list version.
 *
 * Note: All functions assume the given queue is _NOT_ empty.
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* init_queue: initialize a new queue */
struct queue *init_queue()
{
	struct queue *q;

	q = (struct queue *) malloc(sizeof(struct queue));
	if (q == NULL)
		return NULL;

	q->head = NULL;
	q->tail = NULL;
	q->count = 0;

	return q;
}

/* init_queue_node: initialize a new node */
struct queue_node *init_queue_node(data_type_q d)
{
	struct queue_node *node;

	node = (struct queue_node *) malloc(sizeof(struct queue_node));
	if (node == NULL)
		return NULL;

	node->data = d;
	node->next = NULL;
	return node;
}

/* enqueue: add a new node to the end of the queue */
int enqueue(struct queue *q, data_type_q d)
{
	struct queue_node *node;

	node = init_queue_node(d);
	if (node == NULL)
		return -1;
	if (queue_empty(q) == 1) {	/* if the queue is empty */
		q->head = node;	/* init head == NULL */
		q->tail = node; /* init tail == NULL */
	} else {
		q->tail->next = node;
		q->tail = node;
	}
	q->count++;
	return 0;
}

/* dequeue: pop one element from the head of the queue */
data_type_q dequeue(struct queue *q)
{
	struct queue_node *temp;
	data_type_q d;

	if (queue_empty(q) == 1) {	/* queue is already empty */
		perror("Invalid dequeue: Queue is empty\n");
		exit(1);
	}
	if (q->head == q->tail)	/* only one node in the queue */
		q->tail = NULL;	/* pre-set tail to NULL */
	temp = q->head;
	q->head = temp->next;	/* if queue becomes empty, head == NULL */
	d = temp->data;
	free_queue_node(temp);
	q->count--;
	return d;
}

/* queue_empty: return 1 if queue is empty, otherwise 0 */
int queue_empty(struct queue *q)
{
	return (q->count == 0) ? 1 : 0;
}

/* free_queue_node: free the memory of the given queue node */
void free_queue_node(struct queue_node *node)
{
	free(node);
}

/* free_queue: free the memory of the queue */
void free_queue(struct queue *q)
{
	struct queue_node *curr, *temp;

	curr = q->head;
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free_queue_node(temp);
	}
	free(q);
}

void print_queue(struct queue *q)
{
	int i;
	struct queue_node *node;

	if (queue_empty(q) == 1)
		printf("The queue is empty.\n");
	else {
		i = 1;
		node = q->head;
		while (node != NULL) {
			printf("%d. " PRINT_ARG_Q "\n", i++, node->data);
			node = node->next;
		}
	}

}
