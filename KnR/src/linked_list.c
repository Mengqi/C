/**
 * linked_list.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: A template of singly linked list.
 *
 * Note: All functions assume the given linked list is _not_ NULL.
 *	 All positions start from 0.
 */

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/* init_list: initialize a new linked list */
struct linked_list *init_list(void)
{
	struct linked_list *p;

	p = (struct linked_list *) malloc(sizeof(struct linked_list));
	if (p == NULL)
		return NULL;

	p->head = NULL;
	p->end = NULL;
	p->count = 0;

	return p;
}

/* init_list_node: initialize a new node */
struct list_node *init_list_node(int number)
{
	struct list_node *p;

	p = (struct list_node *) malloc(sizeof(struct list_node));
	if (p == NULL)
		return NULL;

	p->num = number;
	p->next = NULL;

	return p;
}

/* insert_list_node: add a new node at the beginning of the list */
void insert_list_node(struct linked_list *list, struct list_node *node)
{
	if (list->head == NULL) {	/* if the list is empty */
		list->head = node;
		list->end = node;
	} else {
		node->next = list->head;
		list->head = node;
	}
	list->count++;
}

/* append_list_node: add a new node at the end of the list */
void append_list_node(struct linked_list *list, struct list_node *node)
{
	if (list->head == NULL) {	/* if the list is empty */
		list->head = node;
		list->end = node;
	} else {
		list->end->next = node;
		list->end = node;
	}
	list->count++;
}

/* add_list_node_by_pos: add a new node at the specified position */
int add_list_node_by_pos(struct linked_list *list, struct list_node *node,
			 int pos)
{
	int i;
	struct list_node *prev_ptr, *curr_ptr;

	if (pos > list->count + 1 || pos < 0)	/* invalid position */
		return -1;

	if (pos == 0)	/* beginning of the list */
		insert_list_node(list, node);
	else if (pos == list->count)	/* end of the list */
		append_list_node(list, node);
	else {
		for (i = 1; i < pos; i++) {
			prev_ptr = curr_ptr;
			curr_ptr = curr_ptr->next;
		}
		prev_ptr->next = node;
		node->next = curr_ptr;
		list->count++;
	}

	return 0;
}

/* search_list_node_by_num: search the node with the given number */
struct list_node *search_list_node_by_num(struct linked_list *list,
					  int number)
{
	struct list_node *p;

	p = list->head;
	while (p != NULL) {
		if (p->num == number)
			return p;
		p = p->next;
	}

	return NULL;
}

/* search_list_node_by_pos: search the node at the given position */
struct list_node *search_list_node_by_pos(struct linked_list *list, int pos)
{
	struct list_node *p;

	if (pos > list->count - 1 || pos < 0)	/* invalid position */
		return NULL;

	if (pos == list->count - 1)	/* at the end of the list */
		return list->end;

	p = list->head;
	while (pos-- > 0)
		p = p->next;

	return p;
}

/* delete_list_node_by_num: delete a node with the given number */
int delete_list_node_by_num(struct linked_list *list, int number)
{
	struct list_node *prev_ptr, *curr_ptr;

	prev_ptr = NULL;
	curr_ptr = list->head;
	while (curr_ptr != NULL) {
		if (curr_ptr->num == number) {
			if (curr_ptr == list->head)	/* node is the head */
				list->head = curr_ptr->next;
			if (curr_ptr == list->end)	/* node is the end */
				list->end = prev_ptr;
			if (prev_ptr != NULL)	/* node is not the head */
				prev_ptr->next = curr_ptr->next;
			free_list_node(curr_ptr);
			list->count--;
			return 0;
		}
		prev_ptr = curr_ptr;
		curr_ptr = curr_ptr->next;
	}

	return -1;
}

/* delete_list_node_by_pos: delete a node at the given position */
int delete_list_node_by_pos(struct linked_list *list, int pos)
{
	struct list_node *prev_ptr, *curr_ptr;

	if (pos > list->count - 1 || pos < 0)	/* invalid position */
		return -1;

	prev_ptr = NULL;
	curr_ptr = list->head;
	while (pos-- > 0) {
		prev_ptr = curr_ptr;
		curr_ptr = curr_ptr->next;
	}

	if (curr_ptr == list->head)	/* node is the head */
		list->head = curr_ptr->next;
	if (curr_ptr == list->end)	/* node is the end */
		list->end = prev_ptr;
	if (prev_ptr != NULL)	/* node is not the head */
		prev_ptr->next = curr_ptr->next;
	free_list_node(curr_ptr);
	list->count--;

	return 0;
}

/* free_list_node: free the memory of the given list node */
void free_list_node(struct list_node *node)
{
	free(node);
}

/* free_linked_list: free the memory of the entire linked list */
void free_linked_list(struct linked_list *list)
{
	struct list_node *p, *temp;

	p = list->head;
	while (p != NULL) {
		temp = p;
		p = p->next;
		free_list_node(p);
	}
}

/* list_empty: return 1 if list is empty, 0 otherwise */
int list_empty(struct linked_list *list)
{
	return (list->head == NULL) ? 1 : 0;
}

/* print_list_node: print the num of a given node */
void print_list_node(struct list_node *node)
{
	printf("num = %d\n", node->num);
}

/* print_list: print the num of the entire linked list */
void print_list(struct linked_list *list)
{
	struct list_node *p;

	p = list->head;
	while (p != NULL) {
		print_list_node(p);
		p = p->next;
	}
}

/* read_linked_list: read the entire linked list from a specified file */
struct linked_list *read_linked_list(char *file_name)
{
	struct linked_list *list;
	struct list_node *node;
	FILE *fp;
	int i, n, num;

	list = init_list();
	if (list == NULL)	/* failed to initialize the linked list */
		return NULL;

	fp = fopen(file_name, "r");
	if (fp == NULL)
		return NULL;

	/* read count from file */
	if (fread(&n, 1, sizeof(int), fp) != sizeof(int))
		goto error;

	/* traverse the linked list, and read all contact from file */
	for (i = 0; i < n; i++) {
		if (fread(&num, 1, sizeof(int), fp) != sizeof(int))
			goto error;
		node = init_list_node(num);
		if (node == NULL)
			goto error;
		/**
		 * Orginial linked-list order: 1-2-3-4-5
		 * Order in the file: 1-2-3-4-5
		 *
		 * Note that we will read node 1 at the begining of
		 * the file. So use append.
		 */
		append_list_node(list, node);
	}
	fclose(fp);
	return list;
error:
	fclose(fp);
	return NULL;
}


/* write_linked_list: write the entire linked list to a specified file */
int write_linked_list(struct linked_list *list, char *file_name)
{
	struct list_node *p;
	FILE *fp;
	int i, n;

	fp = fopen(file_name, "w");
	if (fp == NULL)
		return -1;

	/* write count to file */
	n = list->count;
	if (fwrite(&n, 1, sizeof(int), fp) != sizeof(int))
		goto error;

	/* traverse the linked list, write all nodes to file */
	p = list->head;
	for (i = 0; i < n; i++) {
		if (fwrite(&p->num, 1, sizeof(int), fp) != sizeof(int))
			goto error;
		p = p->next;
	}

	fclose(fp);
	return 0;
error:
	fclose(fp);
	return -1;
}
