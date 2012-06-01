/*
 * menu.c
 *
 * Functions dealing with the menu and general operations.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "contact.h"
#include "contact_book.h"
#include "project_tools.h"

/* pre-processing before launching the main menu */
struct contact_book *pre_proc(void)
{
	struct contact_book *book;

	book = create_contact_book();

	/* load contact book from the file */
	printf("Loading contacts...");
	read_contact_book_from_file(book, DEFAULT_FILE_NAME);
	printf("finished\n");
	printf("\n");

	return book;
}

/* the main frame of the program */
void menu(struct contact_book *book)
{
	int num;

	num = 0;
	while (num != 9) {	
		display_main_menu();
		num = menu_option();
		printf("\n");
		main_menu_action(book, num);
	}
}

/* display the UI of the main menu */
void display_main_menu(void)
{
		/* display main menu */
		printf("****************** MENU ********************\n");
		printf(">> 1. List Contact Names\n");
		printf(">> 2. Display Detailed Contact Info\n");
		printf(">> 3. Add Contact\n");
		printf(">> 4. Edit Contact\n");
		printf(">> 5. Delete Contact\n");
		printf(">> 6. Search Contact\n");
		printf(">> 7. Sort Contact Book\n");
		printf(">> 8. About\n");
		printf(">> 9. Exit\n");
		printf("********************************************\n");
		printf("Input option: ");
}

/* return the int type option */
int menu_option(void)
{
	char option[OPTION_LENGTH];
	int num;

	get_line(option, OPTION_LENGTH);
	num = atoi(option);

	return num;
}

/* function about the action of the main menu */
void main_menu_action(struct contact_book *book, int num)
{
	switch(num) {
	case 1:
		list_contact_name(book);
		menu_pause();
		break;
	case 2:
		display_contact_book(book);
		menu_pause();
		break;
	case 3:
		add_new_contact(book);
		menu_pause();
		break;
	case 4:
		edit_contact_book_by_pos(book);
		menu_pause();
		break;
	case 5:
		delete_contact_menu(book);
		break;
	case 6:
		search_contact_menu(book);
		break;
	case 7:
		sort_contact_menu(book);
		break;
	case 8:
		menu_about();
		menu_pause();
		break;
	case 9:
		menu_exit(book);
		break;
	}
}

/* give a "press any key to continue" */
void menu_pause(void)
{
	char buff[BUFFER_SIZE];

	printf("\n");
	printf("Press any key to continue...");
	get_line(buff, BUFFER_SIZE);
	printf("\n");
}

/* 
 * Function of editing the contact in the given 
 * position of contact book
 */
void edit_contact_book_by_pos(struct contact_book *book)
{
	int num;

	list_contact_name(book);

	printf("Input contact index (0 to quit): ");
	num = menu_option();

	if (num != 0) {
		printf("\n");
		edit_contact_page_by_pos(book, num);
	}
}

/* delete the contact menu */
void delete_contact_menu(struct contact_book *book)
{
	int num;

	num = 0;
	while (num != 9) {	
		display_delete_contact_menu();
		num = menu_option();
		printf("\n");
		delete_contact_menu_action(book, num);
	}
}

/* display the UI of delete contact menu */
void display_delete_contact_menu(void)
{
	printf("************* DELETE CONTACT ***************\n");
	printf(">> 1. Delete a Single Contact by Name\n");
	printf(">> 2. Delete a Single Contact by Index\n");
	printf(">> 3. Delete All Contacts\n");
	printf(">> 9. Back to Main Menu\n");
	printf("********************************************\n");
	printf("Input option: ");
}

void delete_contact_menu_action(struct contact_book *book, int num)
{
	switch(num) {
	case 1:
		delete_contact_book_by_name(book);
		menu_pause();
		break;
	case 2:
		delete_contact_book_by_pos(book);
		menu_pause();
		break;
	case 3:
		delete_all_contacts(book);
		menu_pause();
		break;
	case 9:
		break;
	}
}

void delete_contact_book_by_name(struct contact_book *book)
{
	char buffer[BUFFER_SIZE];

	list_contact_name(book);

	printf("Input contact name: ");
	get_line(buffer, BUFFER_SIZE);

	printf("\n");
	if (delete_contact_page_by_name(book, buffer) == 0) {
		printf("Contact not found.\n");
	} else {
		printf("Deleted.\n");
	}
}

void delete_contact_book_by_pos(struct contact_book *book)
{
	int num;

	list_contact_name(book);

	printf("Input contact index (0 to quit): ");
	num = menu_option();

	if (num != 0) {
		printf("\n");
		if (delete_contact_page_by_pos(book, num) == 0) {
			printf("[ERROR] invalid index %d.\n", num);
		} else {
			printf("Deleted.\n");
		}
	}
}

void delete_all_contacts(struct contact_book *book)
{
	char option[OPTION_LENGTH];

	printf("Do you want to delete ALL contacts in the contact book? (Y/N) ");
	get_line(option, OPTION_LENGTH);
	if (option[0] == 'Y' || option[0] == 'y') {
		remove_all_contacts(book);
		printf("All contacts deleted.\n");
	} else {
		printf("Action cancelled.\n");
	}
}

void search_contact_menu(struct contact_book *book)
{
	int num;

	num = 0;
	while (num != 9) {	
		display_search_contact_menu();
		num = menu_option();
		printf("\n");
		search_contact_menu_action(book, num);
	}
}

/* display search contact menu */
void display_search_contact_menu(void)
{
	printf("************* SEARCH CONTACT ***************\n");
	printf(">> 1. Search Contact by Name\n");
	printf(">> 2. Search Contact by Phone Number\n");
	printf(">> 3. Search Contact by Email Address\n");
	printf(">> 4. Search Contact by QQ number\n");
	printf(">> 9. Back to Main Menu\n");
	printf("********************************************\n");
	printf("Input option: ");
}

void search_contact_menu_action(struct contact_book *book, int num)
{
	switch(num) {
	case 1:
		search_contact_by_name(book);
		menu_pause();
		break;
	case 2:
		search_contact_by_phone_number(book);
		menu_pause();
		break;
	case 3:
		search_contact_by_email(book);
		menu_pause();
		break;
	case 4:
		search_contact_by_qq_number(book);
		menu_pause();
		break;
	case 9:
		break;
	}
}

void search_contact_by_name(struct contact_book *book)
{
	char buffer[BUFFER_SIZE];

	printf("Input contact name: ");
	get_line(buffer, BUFFER_SIZE);

	printf("\n");
	display_contact_book_by_name(book, buffer);
}

void search_contact_by_phone_number(struct contact_book *book)
{
	char buffer[BUFFER_SIZE];

	printf("Input contact phone number: ");
	get_line(buffer, BUFFER_SIZE);
	
	printf("\n");
	display_contact_book_by_phone_number(book, buffer);
}

void search_contact_by_email(struct contact_book *book)
{
	char buffer[BUFFER_SIZE];

	printf("Input contact email address: ");
	get_line(buffer, BUFFER_SIZE);

	printf("\n");
	display_contact_book_by_email(book, buffer);
}

void search_contact_by_qq_number(struct contact_book *book)
{
	char buffer[BUFFER_SIZE];

	printf("Input contact qq number: ");
	get_line(buffer, BUFFER_SIZE);

	printf("\n");
	display_contact_book_by_qq_number(book, buffer);
}

void sort_contact_menu(struct contact_book *book)
{
	int num;

	num = 0;
	while (num != 9) {	
		display_sort_contact_menu();
		num = menu_option();
		printf("\n");
		sort_contact_menu_action(book, num);
	}
}

/* display the UI of sort contact menu */
void display_sort_contact_menu(void)
{
	printf("*************** SORT CONTACT ***************\n");
	printf(">> 1. Sort by Name (From A to Z)\n");
	printf(">> 2. Sort by Name (From Z to A)\n");
	printf(">> 9. Back to Main Menu\n");
	printf("********************************************\n");
	printf("Input option: ");
}

void sort_contact_menu_action(struct contact_book *book, int num)
{
	switch(num) {
	case 1:
		sort_by_name_ascend(book);
		menu_pause();
		break;
	case 2:
		sort_by_name_descend(book);
		menu_pause();
		break;
	case 9:
		break;
	}
}

void sort_by_name_ascend(struct contact_book *book)
{
	printf("Sorting...");
	sort_contact_book_by_name(book, 0);

	printf("finished\n");
}

void sort_by_name_descend(struct contact_book *book)
{
	printf("Sorting...");
	sort_contact_book_by_name(book, 1);

	printf("finished\n");
}

/* display the author info */
void menu_about(void)
{
	printf("***************** ABOUT ********************\n");
	printf(">> Project: The Contact Book\n");
	printf(">> Author: Mengqi Zong\n");
	printf(">> Email: mz2326@columbia.edu\n");
	printf("********************************************\n");
}

void menu_exit(struct contact_book *book)
{
	char buff[BUFFER_SIZE];

	/* save contact_book to file */
	printf("Saving changes...");
	write_contact_book_to_file(book, DEFAULT_FILE_NAME);

	/* free memory */
	remove_contact_book(book);

	printf("finished\n");
	printf("Press any key to exit...");
	get_line(buff, BUFFER_SIZE);
}