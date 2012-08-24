/**
 * queue.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _QUEUE_H
#define _QUEUE_H

typedef int data_type_q;	/* modify data type here */

#define PRINT_ARG_Q "%d"	/* print argument of data_type_q */

struct queue_node {
	data_type_q data;
	struct queue_node *next;
};

struct queue {
	struct queue_node *head;	/* dequeue from head */
	struct queue_node *tail;	/* inqueue from tail */
	int count;	/* number of nodes */
};

/* function declaration */
struct queue *init_queue();
struct queue_node *init_queue_node(data_type_q d);
int enqueue(struct queue *q, data_type_q d);
data_type_q dequeue(struct queue *q);
int queue_empty(struct queue *q);
int free_queue_node(struct queue_node *node);
int free_queue(struct queue *q);
void print_queue(struct queue *q);

#endif	/* _QUEUE_H */
