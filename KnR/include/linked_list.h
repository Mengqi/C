/**
 * linked_list.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef int data_type;	/* modify data type here */

#define PRINT_ARG "%d"	/* the correspond print argument for printf */

struct list_node {
	data_type data;
	struct list_node *next;
};

struct linked_list {
	struct list_node *head;
	struct list_node *end;
	int count;	/* number of nodes */
};

/* function declaration */
struct linked_list *init_list(void);
struct list_node *init_list_node(data_type d);
void insert_list_node(struct linked_list *list, struct list_node *node);
void append_list_node(struct linked_list *list, struct list_node *node);
int add_list_node_by_pos(struct linked_list *list, struct list_node *node,
			 int pos);
struct list_node *search_list_node_by_data(struct linked_list *list,
					   data_type d);
struct list_node *search_list_node_by_pos(struct linked_list *list, int pos);
int delete_list_node_by_data(struct linked_list *list, data_type d);
int delete_list_node_by_pos(struct linked_list *list, int pos);
void free_list_node(struct list_node *node);
void free_linked_list(struct linked_list *list);
int list_empty(struct linked_list *list);
void print_list(struct linked_list *list);
struct linked_list *read_linked_list(char *file_name);
int write_linked_list(struct linked_list *list, char *file_name);

#endif	/* _LINKED_LIST_H */
