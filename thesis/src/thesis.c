/*
 * thesis.c
 *
 * The main function.
 *
 */

#include <stdio.h>
#include <string.h>

#include "menu.h"
#include "contact.h"
#include "contact_book.h"
#include "project_tools.h"

int main(int argc, char* argv[])
{
	struct contact_book *book;

	book = pre_proc();
	menu(book);

	return 0;
}
