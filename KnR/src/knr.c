/*
 * knr.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * The main function.
 */

#include <foo.h>

void foo(void);
void pause_before_exit(void);

int main(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	printf("\n");
	pause_before_exit();
	return 0;
}

/* foo: put all test code here */
void foo(void)
{
	char buff[BUFFER_SIZE];

	printf("%s\n", month_name(11));
}

/* pause_before_exit: pause and wait for input before exiting */
void pause_before_exit(void)
{
	char buff[BUFFER_SIZE];

	printf("Press any key to exit...");
	get_line(buff, BUFFER_SIZE);
}

