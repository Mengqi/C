#ifndef _CONTACT_BOOK_H
#define _CONTACT_BOOK_H

#include "contact.h"

#define ACCOUNT_LENGTH 100

/* the wrapper of contact */
struct contact_page {
	struct contact *c;
	struct contact_page *next;
};

struct contact_book {
	struct contact_page *head;
	char account[ACCOUNT_LENGTH];
	int contact_num;
};

/* function declaration */

struct contact_book *create_contact_book(void);
void init_contact_book(struct contact_book *book);
void input_account_info(struct contact_book *book);
void input_account_name(char *buffer, struct contact_book *book);
int check_account_available(char *account);
struct contact_page *create_contact_page(void);
int edit_contact_page(struct contact_page *page);
int remove_contact_page(struct contact_page *page);
int add_contact_page_at_beginning(struct contact_book *book,
				  struct contact_page *page);
int add_contact_page_at_end(struct contact_book *book,
			    struct contact_page *page);
int add_contact_page_at_pos(struct contact_book *book, int pos,
			    struct contact_page *page);
int delete_contact_page_by_name(struct contact_book *book, char *name);
int delete_contact_page_by_pos(struct contact_book *book, int pos);
void display_contact_book(struct contact_book *book);

#endif /* _CONTACT_BOOK_H */
