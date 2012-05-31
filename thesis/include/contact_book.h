#ifndef _CONTACT_BOOK_H
#define _CONTACT_BOOK_H

#include "contact.h"

#define ACCOUNT_LENGTH 100

/* the wrapper of contact */
struct contact_page {
	struct contact c;
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
int add_account_page_at_beginning(struct contact_book *book,
				  struct contact_page *page);
int add_account_page_at_end(struct contact_book *book,
			    struct contact_page *page);
int add_account_page_at_pos(struct contact_book *book, int pos,
			    struct contact_page *page);
int delete_page_by_name(struct contact_book *book, char *name);



#endif /* _CONTACT_BOOK_H */
