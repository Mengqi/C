/*
 * knr.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * The main function.
 */

#include <foo.h>
#include <nlist.h>

void foo(void);
void pause_before_exit(void);

int main(int argc, char *argv[])
{
	foo();
	pause_before_exit();
	return 0;
}

/* foo: put all test code here */
void foo(void)
{
	int i;
	char *pair[4][2] = {
		"auto", "0",
		"break", "1",
		"case", "2",
		"char", "3"
	};
	struct nlist *temp;

	for (i = 0; i < 4; i++)
		install(pair[i][0], pair[i][1]);
	for (i = 0; i < 4; i++) {
		temp = lookup(pair[i][0]);
		printf("name = %s, defn = %s\n", temp->name, temp->defn);
	}
}

/* pause_before_exit: pause and wait for input before exiting */
void pause_before_exit(void)
{
	char buff[BUFFER_SIZE];

	printf("Press any key to exit...");
	get_line(buff, BUFFER_SIZE);
}

