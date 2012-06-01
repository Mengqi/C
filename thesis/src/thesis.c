#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include "contact.h"
#include "contact_book.h"
#include "project_tools.h"

int main(int argc, char* argv[])
{
	int res;

	res = write_num_to_file("contacts");
	printf("Write: %d\n", res);

	res = read_num_from_file("contacts");
	printf("Read: %d\n", res);
/*
	struct contact_book *book, *book1;
	int res;

	book = create_contact_book();
	add_new_contact(book);
	display_contact_book(book);
	res = write_contact_book_to_file(book, "contacts");
	printf("Write: %d\n", res);
	book1 = create_contact_book();
	res = read_contact_book_from_file(book1, "contacts");
	printf("Read: %d\n", res);
	display_contact_book(book1);
*/
	return 0;
}


int write_num_to_file(char *file_name)
{
	FILE *fp;
	int i, num;

	if ((fp = fopen(file_name, "w")) == NULL)
		return 0;

	printf ("Writting...\n");

	num = 3;
	/* write contact_num */
	if (fwrite(&num, sizeof(int), 1, fp) != sizeof(int))
		return 0;
	fclose(fp);

	return 1;
}

int read_num_from_file(char *file_name)
{
	FILE *fp;
	int num;

	if ((fp = fopen(file_name, "r")) == NULL)
		return 0;

	/* read contact_num */
	if (fread(&num, sizeof(int), 1, fp) != sizeof(int))
		return 0;

	printf("num = %d\n", num);
	fclose(fp);

	return 1;
}
