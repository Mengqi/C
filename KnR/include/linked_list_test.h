/**
 * linked_list_test.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#include "linked_list.h"

#define DEFAULT_FILE_NAME "list.bin"
#define BUFFER_SIZE 2048
#define OPTION_LENGTH 32

/* function declaration */
void linked_list_test(void);
data_type_l get_data(void);
struct linked_list *pre_process(void);
void menu(struct linked_list *list);
void display_main_menu(void);
int menu_option(void);
void main_menu_action(struct linked_list *list, int option);
void menu_pause(void);
void add_menu(struct linked_list *list);
void display_add_menu(void);
void add_menu_action(struct linked_list *list, int option);
void edit_menu(struct linked_list *list);
void delete_menu(struct linked_list *list);
void display_delete_menu(void);
void delete_menu_action(struct linked_list *list, int option);
void delete_by_data(struct linked_list *list);
void delete_by_pos(struct linked_list *list);
void search_menu(struct linked_list *list);
void sort_menu(struct linked_list *list);
void menu_about(void);
void menu_exit(struct linked_list *list);
