#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "contact_book.h"
#include "project_tools.h"

struct contact_book *create_contact_book(void)
{
	struct contact_book *book;

	book = (struct contact_book*)malloc(sizeof(struct contact_book));
	/* not enough memory */
	if (book == NULL)
		return NULL;

	init_contact_book(book);
	input_account_info(book);

	return book;
}

void init_contact_book(struct contact_book *book)
{
	book->head = NULL;
	book->account[0] = '\0';
	book->contact_num = 0;
}

void input_account_info(struct contact_book *book)
{
	char buffer[BUFFER_SIZE];

	input_account_name(buffer, book);
}

void input_account_name(char *buffer, struct contact_book *book)
{
	printf("Please input account name:");
	get_line(buffer, BUFFER_SIZE);

	while (check_account_available(buffer) == 0
	       || strlen(buffer) + 1 > ACCOUNT_LENGTH
	       || strlen(buffer) == 1) {
		if (check_account_available(buffer) == 0) {
			printf("ERROR: account name already exits! "
			       "Please enter again: ");
		} else if (strlen(buffer) + 1 > ACCOUNT_LENGTH) {
			printf("ERROR: the length of the account name "
			       "can be at most %d, please enter again: ",
			       ACCOUNT_LENGTH);
		} else {
			printf("ERROR: the acount name can't be empty! "
			       "Please enter again: ");
		}
		get_line(buffer, BUFFER_SIZE);
	}

	strcpy(book->account, buffer);
}

/* check if the account name is available */
int check_account_available(char *account)
{
	/* currently an empty function */

	return 1;
}

struct contact_page *create_contact_page(void)
{
	struct contact_page *page;
	struct contact *c;

	page = (struct contact_page *)malloc(sizeof(struct contact_page));
	if (page == NULL)
		return NULL;

	c = create_contact();
	if (c == NULL)
		return NULL;

	page->c = c;
	page->next = NULL;

	return page;
}

int edit_contact_page(struct contact_page *page)
{
	edit_contact(page->c);

	return 1;
}

int remove_contact_page(struct contact_page *page)
{
	free(page->c);
	free(page);

	return 1;
}

/* add contact_page at the beginning of the linked-list */
int add_contact_page_at_beginning(struct contact_book *book,
				  struct contact_page *page)
{
	if (book->head == NULL) {
		book->head = page;
		page->next = NULL;
	} else {
		page->next = book->head;
		book->head = page;
	}

	book->contact_num++;

	return 1;
}

/* add contact_page at the end of the linked-list */
int add_contact_page_at_end(struct contact_book *book,
			    struct contact_page *page)
{
	struct contact_page *temp;

	if (book->head == NULL) {
		/* if list is empty, add page at head directly */
		book->head = page;
		page->next =NULL;
	} else {
		temp = book->head;
		/* traverse down to the end of the list */
		while (temp->next != NULL)
			temp = temp->next;

		/* append at the end of the list */
		temp->next = page;
		page->next = NULL;
	}

	book->contact_num++;

	return 1;
}

int add_contact_page_at_pos(struct contact_book *book, int pos,
			    struct contact_page *page)
{
	int i;
	struct contact_page *prev_ptr, *cur_ptr;

	cur_ptr = book->head;

	if (pos <= 0 || pos > book->contact_num) {
		return 0;
	} else if (pos == 1) {
		add_contact_page_at_beginning(book, page);
	} else {
		for (i = 1; i < pos; i++) {
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next;
		}

		prev_ptr->next = page;
		page->next = cur_ptr;
		
		book->contact_num++;
	}

	return 1;
}

int delete_contact_page_by_name(struct contact_book *book, char *name)
{
	struct contact_page *prev_ptr, *cur_ptr;

	cur_ptr = book->head;

	while(cur_ptr != NULL) {
		if (strcmp(cur_ptr->c->name, name) == 0) {
			if (cur_ptr == book->head) {
				book->head = book->head->next;
				remove_contact_page(cur_ptr);
				book->contact_num--;
				return 1;
			} else {
				prev_ptr->next = cur_ptr->next;
				remove_contact_page(cur_ptr);
				book->contact_num--;
				return 1;
			}
		} else {
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next;
		}
	}

	/* name not found */
	return 0;
}

int delete_contact_page_by_pos(struct contact_book *book, int pos)
{
	struct contact_page *prev_ptr, *cur_ptr;
	int i;

	cur_ptr = book->head;

	if (pos > book->contact_num || pos <= 0) {
		return 0;
	} else if (pos == 1) {
		book->head = cur_ptr->next;
		remove_contact_page(cur_ptr);
		book->contact_num--;
		return 1;
	} else {
		for (i = 1; i < pos; i++) {
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next;
		}

		prev_ptr->next = cur_ptr->next;
		remove_contact_page(cur_ptr);
		book->contact_num--;
		return 1;
	}
}

void display_contact_book(struct contact_book *book)
{
	struct contact_page *cur_ptr;
	int i;

	i = 1;
	cur_ptr = book->head;

	if (cur_ptr == NULL) {
		printf("The contact book is empty.\n");
	} else {
		while (cur_ptr != NULL) {
			printf("Contact %d\n", i);
			display_contact(cur_ptr->c);
		}
	}
}

