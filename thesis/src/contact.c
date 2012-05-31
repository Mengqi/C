/*
 * contact.h
 *
 * Functions that dealing with a single contact.
 *
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "contact.h"
#include "project_tools.h"

/* create a new contact */
struct contact *create_contact(void)
{
	struct contact *c;

	c = (struct contact *)malloc(sizeof(struct contact));
	/* not enough memory */
	if (c == NULL)
		return NULL;

	init_contact(c);
	input_contact(c);

	return c;
}

/* initiate all the texts in the contact to be empty string */
void init_contact(struct contact *c)
{
	c->name[0] = '\0';
	c->phone_number[0] = '\0';
	c->address[0] = '\0';
	c->email[0] = '\0';
	c->qq_number[0] = '\0';
	c->note[0] = '\0';
}

/* input the text in the contact */
int input_contact(struct contact *c)
{
	char buffer[BUFFER_SIZE];

	input_name(buffer, c);
	input_phone_number(buffer, c);
	input_address(buffer, c);
	input_email(buffer, c);;
	input_qq_number(buffer, c);;
	input_note(buffer, c);;

	return 1;
}

void input_name(char *buffer, struct contact *c)
{
	printf("Please input contact's name: ");
	get_line(buffer, BUFFER_SIZE);
	while (strlen(buffer) + 1 > NAME_LENGTH
	       || strlen(buffer) == 1) {
		if (strlen(buffer) + 1 > NAME_LENGTH) {
			printf("ERROR: The length of the name can be at "
			       "most %d, please enter again: ", NAME_LENGTH);
		} else {
			printf("ERROR: The name cant not be empty, "
				"please enter again: ");
		}
		get_line(buffer, BUFFER_SIZE);
	}
	strcpy(c->name, buffer);
}

void input_phone_number(char *buffer, struct contact *c)
{
	printf("Please input contact's phone number: ");
	get_line(buffer, BUFFER_SIZE);
	while (strlen(buffer) + 1 > PHONE_LENGTH) {
		printf("ERROR: The length of the phone number can be at "
		       "most %d, please enter again: ", PHONE_LENGTH);
		get_line(buffer, BUFFER_SIZE);
	}
	strcpy(c->phone_number, buffer);
}

void input_address(char *buffer, struct contact *c)
{
	printf("Please input contact's address: ");
	get_line(buffer, BUFFER_SIZE);
	while (strlen(buffer) + 1 > ADDRESS_LENGTH) {
		printf("ERROR: The length of the address can be at "
		       "most %d, please enter again: ", ADDRESS_LENGTH);
		get_line(buffer, BUFFER_SIZE);
	}
	strcpy(c->address, buffer);
}

void input_email(char *buffer, struct contact *c)
{
	printf("Please input contact's email: ");
	get_line(buffer, BUFFER_SIZE);
	while (strlen(buffer) + 1 > EMAIL_LENGTH
	       || check_email_format(buffer) == 0) {
		if (strlen(buffer) + 1 > EMAIL_LENGTH) {
			printf("ERROR: The length of email can be at most"
			       " %d, please enter again: ", EMAIL_LENGTH);
		} else {
			printf("ERROR: Invaild email address, please enter "
			       "again: ");
		}
		get_line(buffer, BUFFER_SIZE);
	}
	strcpy(c->email, buffer);
}

/*
 * Check the format of the email address. If
 * email is valid, then return 1, otherwise
 * return 0.
 */
int check_email_format(char *email)
{
	int pos, pos_at, count_at, count_dot;

	/* If the email is empty, then it is valid 
	 * Note that '\n' counts as a character
	 */
	if (strlen(email) == 1)
		return 1;
	/*
	 * If the email is not empty. Then if and only
	 * if there is one '@' and at most three'.' after
	 * "@" in the email, then the email is valid.
	 */

	/* check '@' */
	count_at = 0;
	for (pos = 0; pos <= strlen(email); pos++) {
		if (email[pos] == '@') {
			pos_at = pos;
			count_at++;
		}
	}
	if (count_at != 1)
		return 0;

	/* check '.' */
	count_dot = 0;
	for (pos = pos_at; pos <= strlen(email); pos++) {
		if (email[pos] == '.') {
			count_dot++;
		}
	}
	if (count_dot > 0 && count_dot <= 3) {
		return 1;
	} else {
		return 0;
	}
}

void input_qq_number(char *buffer, struct contact *c)
{
	printf("Please input contact's qq number: ");
	get_line(buffer, BUFFER_SIZE);
	while (strlen(buffer) + 1 > QQ_LENGTH) {
		printf("ERROR: The length of the qq number can be at "
		       "most %d, please enter again: ", QQ_LENGTH);
		get_line(buffer, BUFFER_SIZE);
	}
	strcpy(c->qq_number, buffer);
}

void input_note(char *buffer, struct contact *c)
{
	printf("Please input contact's note: ");
	get_line(buffer, BUFFER_SIZE);
	while (strlen(buffer) + 1 > NOTE_LENGTH) {
		printf("ERROR: The length of the note can be at "
		       "most %d, please enter again: ", NOTE_LENGTH);
		get_line(buffer, BUFFER_SIZE);
	}
	strcpy(c->note, buffer);
}

void display_contact(struct contact *c)
{
	printf("Name: %s", c->name);
	printf("Phone Number: %s", c->phone_number);
	printf("Address: %s", c->address);
	printf("Email: %s", c->email);
	printf("QQ: %s", c->qq_number);
	printf("Note: %s", c->note);
}

int edit_contact(struct contact *c)
{
	char buffer[BUFFER_SIZE];

	edit_name(buffer, c);
	edit_phone_number(buffer, c);
	edit_address(buffer, c);
	edit_email(buffer, c);
	edit_qq_number(buffer, c);
	edit_note(buffer, c);

	return 1;
}

void edit_name(char *buffer, struct contact *c)
{
	printf("Name: %s", c->name);
	if (edit_option() == 1)
		input_name(buffer, c);
}

void edit_phone_number(char *buffer, struct contact *c)
{
	printf("Phone Number: %s", c->phone_number);
	if (edit_option() == 1)
		input_phone_number(buffer, c);
}

void edit_address(char *buffer, struct contact *c)
{
	printf("Address: %s", c->address);
	if (edit_option() == 1)
		input_address(buffer, c);
}

void edit_email(char *buffer, struct contact *c)
{
	printf("Email: %s", c->email);
	if (edit_option() == 1)
		input_email(buffer, c);
}

void edit_qq_number(char *buffer, struct contact *c)
{
	printf("QQ: %s", c->qq_number);
	if (edit_option() == 1)
		input_qq_number(buffer, c);
}

void edit_note(char *buffer, struct contact *c)
{
	printf("Note: %s", c->note);
	if (edit_option() == 1)
		input_note(buffer, c);
}

/* return 1 if you want to edit, otherwise return 0 */
int edit_option(void)
{
	char option[OPTION_LENGTH];

	printf("Do you want to edit it? (Y/N)\n");
	get_line(option, OPTION_LENGTH);
	if (option[0] == 'Y' || option[0] == 'y')
		return 1;
	else
		return 0;
}

int remove_contact(struct contact *c)
{
	if (c == NULL)
		return 0;

	free(c);
	return 1;
}

