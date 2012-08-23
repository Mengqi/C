/**
 * linked_list.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct list_node {
	int num;
	struct list_node *next;
};

struct linked_list {
	struct list_node *head;
	struct list_node *end;
	int count;	/* number of nodes */
};

struct linked_list *init_list(void);
struct list_node *init_list_node(int number);
void insert_list_node(struct linked_list *list, struct list_node *node);
void append_list_node(struct linked_list *list, struct list_node *node);
int add_list_node_by_pos(struct linked_list *list, struct list_node *node,
			 int pos);
struct list_node *search_list_node_by_num(struct linked_list *list, int number);
struct list_node *search_list_node_by_pos(struct linked_list *list, int pos);
int delete_list_node_by_num(struct linked_list *list, int number);
int delete_list_node_by_pos(struct linked_list *list, int pos);
void free_list_node(struct list_node *node);
void free_linked_list(struct linked_list *list);
int list_empty(struct linked_list *list);
void print_list_node(struct list_node *node);
void print_list(struct linked_list *list);
struct linked_list *read_linked_list(char *file_name);
int write_linked_list(struct linked_list *list, char *file_name);

#endif	/* _LINKED_LIST_H */
