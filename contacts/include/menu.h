#ifndef _MENU_H
#define _MENU_H

#define DEFAULT_FILE_NAME "contacts.bin"

/* function declaration */
struct contact_book *pre_proc(void);
void menu(struct contact_book *book);
void display_main_menu(void);
int menu_option(void);
void main_menu_action(struct contact_book *book, int num);
void menu_pause(void);
void edit_contact_book_by_pos(struct contact_book *book);
void delete_contact_menu(struct contact_book *book);
void display_delete_contact_menu(void);
void delete_contact_menu_action(struct contact_book *book, int num);
void delete_contact_book_by_name(struct contact_book *book);
void delete_contact_book_by_pos(struct contact_book *book);
void delete_all_contacts(struct contact_book *book);
void search_contact_menu(struct contact_book *book);
void display_search_contact_menu(void);
void search_contact_menu_action(struct contact_book *book, int num);
void search_contact_by_name(struct contact_book *book);
void search_contact_by_phone_number(struct contact_book *book);
void search_contact_by_email(struct contact_book *book);
void search_contact_by_qq_number(struct contact_book *book);
void sort_contact_menu(struct contact_book *book);
void display_sort_contact_menu(void);
void sort_contact_menu_action(struct contact_book *book, int num);
void sort_by_name_ascend(struct contact_book *book);
void sort_by_name_descend(struct contact_book *book);
void menu_about(void);
void menu_exit(struct contact_book *book);

#endif
