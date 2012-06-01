#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <fcntl.h>

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

	return book;
}

void init_contact_book(struct contact_book *book)
{
	book->head = NULL;
	book->contact_num = 0;
}

/* add a new contact to the contact_book */
int add_new_contact(struct contact_book *book)
{
	struct contact_page *page;

	page = create_contact_page();

	if (page == NULL) {
		return 0;
	} else {
		add_contact_page_at_beginning(book, page);
	}

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
			cur_ptr = cur_ptr->next;
		}
	}
}

int write_contact_book_to_file(struct contact_book *book, char *file_name)
{
	struct contact_page *page;
	int fd;
	int i, num;

	if ((fd = open(file_name, O_WRONLY, 0)) == -1)
		return 0;

	num = book->contact_num;
	/* write contact_num */
	if (write(file_name, &num, sizeof(int)) != sizeof(int))
		return 0;

	/* traverse the linked list, and write all contact to file */
	page = book->head;
	for (i = 0; i < num; i++) {
		if (write(file_name, page->c, sizeof(struct contact))
		    != sizeof(struct contact))
			return 0;
	}
	
	return 1;
}

int read_contact_book_from_file(struct contact_book *book, char *file_name)
{

	int fd;
	int i, num;

	if ((fd = open(file_name, O_RDONLY, 0)) == -1)
		return 0;

	/* read contact_num */
	if (write(file_name, &num, sizeof(int)) != sizeof(int))
		return 0;

	/* traverse the linked list, and write all contact to file */
	for (i = 0; i < num; i++) {
		if (read_contact_from_file(book, file_name) == 0)
			return 0;
	}

	return 1;
}

/* read a contact from file, then create a new contact_page, add it to
 * the contact_book
 */
int read_contact_from_file(struct contact_book *book, char *file_name)
{
	struct contact_page *page;
	struct contact *c;

	page = (struct contact_page *)malloc(sizeof(struct contact_page));
	/* not enough memory */
	if (page == NULL)
		return 0;	

	c = (struct contact *)malloc(sizeof(struct contact));
	/* not enough memory */
	if (c == NULL)
		return 0;

	if (read(file_name, c, sizeof(struct contact))
	    != sizeof(struct contact))
		return 0;

	page->c = c;

	add_contact_page_at_end(book, page);

	return 1;
}
