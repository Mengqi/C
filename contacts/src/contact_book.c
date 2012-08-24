/*
 * contact_book.c
 *
 * Functions dealing with the linked_list, contact_book.
 *
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "contact_book.h"
#include "project_tools.h"

/* create an empty contact book */
struct contact_book *create_contact_book(void)
{
	struct contact_book *book;

	book = (struct contact_book *) malloc(sizeof(struct contact_book));
	/* not enough memory */
	if (book == NULL)
		return NULL;

	init_contact_book(book);

	return book;
}

/* initiate the empty contact book */
void init_contact_book(struct contact_book *book)
{
	book->head = NULL;
	book->contact_num = 0;
}

/* Add a new contact to the contact_book */
int add_new_contact(struct contact_book *book)
{
	struct contact_page *page;

	page = create_contact_page();

	if (page == NULL)
		return 0;
	else
		add_contact_page_at_beginning(book, page);

	return 1;
}

/*
 * Create a new contact page, this processdure requires
 * user to input information of the new contact
 */
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

/* Edit the contact of the contact book in the specified postion */
void edit_contact_page_by_pos(struct contact_book *book, int pos)
{
	struct contact_page *cur_ptr;
	int i;

	i = 1;
	cur_ptr = book->head;

	if (pos <= 0 || pos > book->contact_num) {
		printf("[ERROR] Invalid index %d.\n", pos);
	} else {
		while (i < pos) {
			cur_ptr = cur_ptr->next;
			i++;
		}

		edit_contact_page(cur_ptr);
	}
}

/* free the memory space of the contact page, including
 * free the memory space of contact
 */
int remove_contact_page(struct contact_page *page)
{
	free(page->c);
	free(page);

	return 1;
}

/* Add contact_page at the beginning of the linked-list */
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

/* Add contact_page at the end of the linked-list */
int add_contact_page_at_end(struct contact_book *book,
			    struct contact_page *page)
{
	struct contact_page *temp;

	if (book->head == NULL) {
		/* if list is empty, add page at head directly */
		book->head = page;
		page->next = NULL;
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

/* Add contact_page at the given position of the linked-list */
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

/* Delete all contact pages in the contact book that have the specified name */
int delete_contact_page_by_name(struct contact_book *book, char *name)
{
	struct contact_page *prev_ptr, *cur_ptr;

	cur_ptr = book->head;

	while (cur_ptr != NULL) {
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

/* Delete the contact_page at the given position of the linked-list */
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

/* Display all the contacts in the contact book */
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
			printf("************ Contact %d ************\n", i);
			display_contact(cur_ptr->c);
			cur_ptr = cur_ptr->next;
			i++;
		}
		printf("***********************************\n");
	}
}

/* List the names (only) of all contacts in the contact book */
void list_contact_name(struct contact_book *book)
{
	struct contact_page *cur_ptr;
	int i;

	i = 1;
	cur_ptr = book->head;

	if (cur_ptr == NULL) {
		printf("The contact book is empty.\n");
	} else {
		printf("************ Contacts ***********\n");
		while (cur_ptr != NULL) {
			printf(">> %d. %s", i, cur_ptr->c->name);
			cur_ptr = cur_ptr->next;
			i++;
		}
		printf("*********************************\n");
	}
}

/* Display contacts in the contact book that have the specified name */
void display_contact_book_by_name(struct contact_book *book, char *name)
{
	struct contact_page *cur_ptr;
	int i, find_num;

	i = 1;
	find_num = 0;
	cur_ptr = book->head;

	if (cur_ptr == NULL) {
		printf("The contact book is empty.\n");
	} else {
		while (cur_ptr != NULL) {
			if (strcmp(name, cur_ptr->c->name) == 0) {
				printf("************ Contact %d ************\n",
				       i);
				display_contact(cur_ptr->c);
				find_num++;
			}
			i++;
			cur_ptr = cur_ptr->next;
		}
		if (find_num == 0)
			printf("No contact was found with the specified"
			       " conditon.\n");
		else
			printf("***********************************\n");
	}
}

/* Display contacts in the contact book that have the specified phone number */
void display_contact_book_by_phone_number(struct contact_book *book,
					  char *phone)
{
	struct contact_page *cur_ptr;
	int i, find_num;

	i = 1;
	find_num = 0;
	cur_ptr = book->head;

	if (cur_ptr == NULL) {
		printf("The contact book is empty.\n");
	} else {
		while (cur_ptr != NULL) {
			if (strcmp(phone, cur_ptr->c->phone_number) == 0) {
				printf("************ Contact %d ************\n",
				       i);
				display_contact(cur_ptr->c);
				find_num++;
			}
			i++;
			cur_ptr = cur_ptr->next;
		}
		if (find_num == 0)
			printf("No contact was found with the specified"
			       " conditon.\n");
		else
			printf("***********************************\n");
	}
}

/* Display contacts in the contact book that have the specified email address */
void display_contact_book_by_email(struct contact_book *book, char *email)
{
	struct contact_page *cur_ptr;
	int i, find_num;

	i = 1;
	find_num = 0;
	cur_ptr = book->head;

	if (cur_ptr == NULL) {
		printf("The contact book is empty.\n");
	} else {
		while (cur_ptr != NULL) {
			if (strcmp(email, cur_ptr->c->email) == 0) {
				printf("************ Contact %d ************\n",
				       i);
				display_contact(cur_ptr->c);
				find_num++;
			}
			i++;
			cur_ptr = cur_ptr->next;
		}
		if (find_num == 0)
			printf("No contact was found with the specified"
			       " conditon.\n");
		else
			printf("***********************************\n");
	}
}

/* Display contacts in the contact book that have the specified qq number */
void display_contact_book_by_qq_number(struct contact_book *book, char *qq)
{
	struct contact_page *cur_ptr;
	int i, find_num;

	i = 1;
	find_num = 0;
	cur_ptr = book->head;

	if (cur_ptr == NULL) {
		printf("The contact book is empty.\n");
	} else {
		while (cur_ptr != NULL) {
			if (strcmp(qq, cur_ptr->c->qq_number) == 0) {
				printf("************ Contact %d ************\n",
				       i);
				display_contact(cur_ptr->c);
				find_num++;
			}
			i++;
			cur_ptr = cur_ptr->next;
		}
		if (find_num == 0)
			printf("No contact was found with the specified"
			       " conditon.\n");
		else
			printf("***********************************\n");
	}
}

/* Write the entire contact book to the specified file */
int write_contact_book_to_file(struct contact_book *book, char *file_name)
{
	struct contact_page *page;
	FILE *fp;
	int i, num;

	fp = fopen(file_name, "w");
	if (fp == NULL)
		return 0;

	/* write contact_num to file */
	num = book->contact_num;
	if (fwrite(&num, 1, sizeof(int), fp) != sizeof(int)) {
		fclose(fp);
		return 0;
	}

	/* traverse the linked list, and write all contacts to file */
	page = book->head;
	for (i = 0; i < num; i++) {
		if (fwrite(page->c, 1, sizeof(struct contact), fp)
		    != sizeof(struct contact)) {
			fclose(fp);
			return 0;
		}
		page = page->next;
	}

	fclose(fp);
	return 1;
}

/* Read the entire contact book from the specified file */
int read_contact_book_from_file(struct contact_book *book, char *file_name)
{
	FILE *fp;
	int i, num;

	fp = fopen(file_name, "r");
	if (fp == NULL)
		return 0;

	/* read contact_num from file */
	if (fread(&num, 1, sizeof(int), fp) != sizeof(int)) {
		fclose(fp);
		return 0;
	}

	/* traverse the linked list, and read all contact from file */
	for (i = 0; i < num; i++) {
		if (read_contact_from_file(book, fp) == 0) {
			fclose(fp);
			return 0;
		}
	}

	fclose(fp);
	return 1;
}

/*
 * Read a single contact from the file. Then create a new contact_page
 * for the contact, add it to the contact_book
 */
int read_contact_from_file(struct contact_book *book, FILE *fp)
{
	struct contact_page *page;
	struct contact *c;

	page = (struct contact_page *)malloc(sizeof(struct contact_page));
	/* not enough memory for contact_page */
	if (page == NULL)
		return 0;

	c = (struct contact *)malloc(sizeof(struct contact));
	/* not enough memory for contact */
	if (c == NULL)
		return 0;

	if (fread(c, 1, sizeof(struct contact), fp) != sizeof(struct contact))
		return 0;

	page->c = c;
	/*
	 * Orginial linked-list order: 1-2-3-4-5
	 * Order in the file: 1-2-3-4-5
	 *
	 * Since we read contact 1 at the begining of the file,
	 * We have to put each new contact page at the end
	 * of the linked-list. So here we use function
	 * add_contact_page_at_end().
	 */
	add_contact_page_at_end(book, page);

	return 1;
}

/* Free memory space of the entire contact book manually */
void remove_contact_book(struct contact_book *book)
{
	remove_all_contacts(book);
	free(book);
	book = NULL;
}

/* Remove all contacts in the contact book */
void remove_all_contacts(struct contact_book *book)
{
	struct contact_page *cur_ptr;

	while (book->head != NULL) {
		cur_ptr = book->head;
		book->head = book->head->next;
		remove_contact_page(cur_ptr);
		book->contact_num--;
	}
}

/*
 * Sort all the contacts in the contact book by name.
 * mode = 0: ascending order, from A to Z.
 * mode = 1: descending order, from Z to A.
 * The sort algorithm: bubble sort.
 */
int sort_contact_book_by_name(struct contact_book *book, int mode)
{
	struct contact_page *prev_ptr, *cur_ptr, *after_ptr, *temp;
	int i, j, n;
	int switch_flag;	/* 1 to do the swithing, 0 for nothing */

	if (book->head == NULL)
		return 1;

	n = book->contact_num;

	/* the bubble sort */
	for (i = n - 1; i > 0; i--) {
		prev_ptr = book->head;
		cur_ptr = book->head;
		after_ptr = book->head->next;

		for (j = 0; j < i; j++) {
			switch_flag = 0;
			if (mode == 0) {
				/* ascending order, use '>' */
				if (strcmp(cur_ptr->c->name,
					   after_ptr->c->name) > 0)
					switch_flag = 1;
			} else {
				/* descdening order, use '<' */
				if (strcmp(cur_ptr->c->name,
					   after_ptr->c->name) < 0)
					switch_flag = 1;
			}

			if (switch_flag == 1) {
				/* the switching of cur_ptr and after_ptr */
				if (cur_ptr == book->head) {
					/* switch links */
					cur_ptr->next = after_ptr->next;
					after_ptr->next = cur_ptr;
					/* switch names */
					temp = after_ptr;
					after_ptr = cur_ptr;
					cur_ptr = temp;
					prev_ptr = cur_ptr;
					book->head = cur_ptr;
				} else {
					/* switch links */
					cur_ptr->next = after_ptr->next;
					after_ptr->next = cur_ptr;
					prev_ptr->next = after_ptr;
					/* since two ptr have changed their
					 * position,they have to swap their
					 * names */
					temp = after_ptr;
					after_ptr = cur_ptr;
					cur_ptr = temp;
				}
			}

			/* move forward */
			prev_ptr = cur_ptr;
			cur_ptr = after_ptr;
			after_ptr = after_ptr->next;
		}
	}

	return 1;
}
