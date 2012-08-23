/**
 * linked_list_test.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: Test functions for linked_list.
 */

#include <stdio.h>
#include <stdlib.h>

#include "foo.h"
#include "linked_list_test.h"

/* linked_list_test: call this function to begin the test */
void linked_list_test(void)
{
	struct linked_list *list;

	list = pre_process();
	menu(list);
}

/* pre_process: pre-processing before launching the main menu */
struct linked_list *pre_process(void)
{
	struct linked_list *list;

	/* load linked list from the file */
	printf("Loading data...");
	list = read_linked_list(DEFAULT_FILE_NAME);
	if (list == NULL)
		list = init_list();
	printf("finished\n");
	printf("\n");

	return list;
}

/* menu: the main frame of the test process */
void menu(struct linked_list *list)
{
	int num;

	num = 0;
	while (num != 9) {
		display_main_menu();
		num = menu_option();
		printf("\n");
		main_menu_action(list, num);
	}
}

/* display_main_menu: display the UI of the main menu */
void display_main_menu(void)
{
	/* display main menu */
	printf("****************** MENU ********************\n");
	printf(">> 1. Display\n");
	printf(">> 3. Add\n");
	printf(">> 4. Edit\n");
	printf(">> 5. Delete\n");
	printf(">> 6. Search\n");
	printf(">> 7. Sort\n");
	printf(">> 8. About\n");
	printf(">> 9. Exit\n");
	printf("********************************************\n");
	printf("Input option: ");
}

/* menu_option: return the int type option */
int menu_option(void)
{
	char option[OPTION_LENGTH];
	int num;

	get_line(option, OPTION_LENGTH);
	num = atoi(option);

	return num;
}

/* main_menu_action: the action of the main menu */
void main_menu_action(struct linked_list *list, int num)
{
	switch (num) {
	case 1:
		print_list(list);
		menu_pause();
		break;
	case 3:
		add_menu(list);
		break;
	case 4:
		edit_menu(list);
		menu_pause();
		break;
	case 5:
		delete_menu(list);
		break;
	case 6:
		search_menu(list);
		break;
	case 7:
		sort_menu(list);
		break;
	case 8:
		menu_about();
		menu_pause();
		break;
	case 9:
		menu_exit(list);
		break;
	}
}

/* menu_pause: display "press any key to continue..." and pause */
void menu_pause(void)
{
	char buff[BUFFER_SIZE];

	printf("\n");
	printf("Press any key to continue...");
	get_line(buff, BUFFER_SIZE);
	printf("\n");
}

/* add_menu: the menu for adding new nodes */
void add_menu(struct linked_list *list)
{
	int option;

	display_add_menu();
	option = menu_option();
	add_menu_action(list, option);
}

/* display_add_menu: display the UI of add menu */
void display_add_menu(void)
{
	printf("***************** ADD MENU *****************\n");
	printf(">> 1. Insert\n");
	printf(">> 2. Append\n");
	printf(">> 3. Add by Positions\n");
	printf(">> 9. Back to Main Menu\n");
	printf("********************************************\n");
	printf("Input option: ");
}

/* add_menu_action: the action for add menu */
void add_menu_action(struct linked_list *list, int option)
{
	int num, pos;
	struct list_node *p;

	printf("Input num: ");
	num = menu_option();
	p = init_list_node(num);
	if (p == NULL)
		printf("Failed to add new node\n");

	switch (option) {
	case 1:
		insert_list_node(list, p);
		printf("Done.\n");
		menu_pause();
		break;
	case 2:
		append_list_node(list, p);
		menu_pause();
		printf("Done.\n");
		break;
	case 3:
		printf("Input position: ");
		pos = menu_option();
		if (add_list_node_by_pos(list, p, pos-1) < 0)
			printf("Failed to add new node\n");
		printf("Done.\n");
		menu_pause();
		break;
	case 9:
		break;
	}
}

/* edit_menu: the menu for editing nodes */
void edit_menu(struct linked_list *list)
{
	int index, num;
	struct list_node *p;

	print_list(list);
	printf("\n");

	printf("Input index: ");
	index = menu_option();
	if (index > 0) {
		printf("\n");
		p = search_list_node_by_pos(list, index-1);
		printf("Please input num: ");
		num = menu_option();
		p->num = num;
	}
}

/* delete_menu: the menu for deleting nodes */
void delete_menu(struct linked_list *list)
{
	int num;

	num = 0;
	while (num != 9) {
		display_delete_menu();
		num = menu_option();
		printf("\n");
		delete_menu_action(list, num);
	}
}

/* display_delete_menu: display the UI of delete contact menu */
void display_delete_menu(void)
{
	printf("************* DELETE CONTACT ***************\n");
	printf(">> 1. Delete by Num\n");
	printf(">> 2. Delete by Index\n");
	printf(">> 3. Delete All\n");
	printf(">> 9. Back to Main Menu\n");
	printf("********************************************\n");
	printf("Input option: ");
}

/* delete_menu_action: the action for delete menu */
void delete_menu_action(struct linked_list *list, int num)
{
	switch (num) {
	case 1:
		delete_by_num(list);
		menu_pause();
		break;
	case 2:
		delete_by_pos(list);
		menu_pause();
		break;
	case 3:
		printf("Haven't implemented yet :<\n");
		menu_pause();
		break;
	case 9:
		break;
	}
}

/* delete_by_num: actions of deleting a node with a specified num */
void delete_by_num(struct linked_list *list)
{
	int num;

	print_list(list);

	printf("Input num: ");
	num = menu_option();

	printf("\n");
	if (delete_list_node_by_num(list, num) < 0)
		printf("Node not found.\n");
	else
		printf("Deleted.\n");
}

/* delete_by_pos: actions of deleting a node in a specified position */
void delete_by_pos(struct linked_list *list)
{
	int pos;

	print_list(list);

	printf("Input postion (0 to quit): ");
	pos = menu_option();

	if (pos != 0) {
		printf("\n");
		if (delete_list_node_by_pos(list, pos-1) < 0)
			printf("Invalid position %d.\n", pos);
		else
			printf("Deleted.\n");
	}
}

/* search_menu: the menu for searching nodes */
void search_menu(struct linked_list *list)
{
	printf("Haven't implemented yet :<\n");
}

/* sort_menu: the menu for sorting nodes */
void sort_menu(struct linked_list *list)
{
	printf("Haven't implemented yet :<\n");
}

/* menu_about: display the information about the program */
void menu_about(void)
{
	printf("***************** ABOUT ********************\n");
	printf(">> Project: Test for linked list\n");
	printf(">> Author: Mengqi Zong\n");
	printf(">> Email: zongmengqi@gmail.com\n");
	printf("********************************************\n");
}

void menu_exit(struct linked_list *list)
{
	char buff[BUFFER_SIZE];

	/* save linked list to file */
	printf("Saving changes...");
	write_linked_list(list, DEFAULT_FILE_NAME);

	/* free memory */
	free_linked_list(list);

	printf("finished\n");
	printf("Press any key to exit...");
	get_line(buff, BUFFER_SIZE);
}

