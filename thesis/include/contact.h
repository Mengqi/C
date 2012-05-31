#ifndef _CONTACTS_H
#define _CONTACTS_H

#define NAME_LENGTH 100
#define PHONE_LENGTH 100
#define ADDRESS_LENGTH 200
#define EMAIL_LENGTH 100
#define QQ_LENGTH 100
#define NOTE_LENGTH 2000

#define BUFFER_SIZE 5000
#define OPTION_LENGTH 20

struct contact {
	char name[NAME_LENGTH];
	char phone_number[PHONE_LENGTH];
	char address[ADDRESS_LENGTH];
	char email[EMAIL_LENGTH];
	char qq_number[QQ_LENGTH];
	char note[NOTE_LENGTH];
};

/* function declaration */
struct contact *create_contact(void);
void init_contact(struct contact *c);
int input_contact(struct contact *c);
void input_name(char *buffer, struct contact *c);
void input_phone_number(char *buffer, struct contact *c);
void input_address(char *buffer, struct contact *c);
void input_email(char *buffer, struct contact *c);
int check_email_format(char *email);
void input_qq_number(char *buffer, struct contact *c);
void input_note(char *buffer, struct contact *c);
void display_contact(struct contact *c);
int edit_contact(struct contact *c);
void edit_name(char *buffer, struct contact *c);
void edit_phone_number(char *buffer, struct contact *c);
void edit_address(char *buffer, struct contact *c);
void edit_email(char *buffer, struct contact *c);
void edit_qq_number(char *buffer, struct contact *c);
void edit_note(char *buffer, struct contact *c);
int edit_option(void);
int remove_contact(struct contact *c);

#endif /* _CONTACTS_H */
