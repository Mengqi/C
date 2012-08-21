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
	foo();
	pause_before_exit();
	return 0;
}

/* foo: put all test code here */
void foo(void)
{
	char buff[BUFFER_SIZE];
	int i, pattern[5];

	pattern[1] = 4;
	pattern[2] = 5;
	pattern[3] = 2;
	pattern[4] = 1;
	pattern[5] = 3;
	qsort(pattern, 1, 5);
	for (i = 1; i <=5; i++)
		printf("%d", pattern[i]);
	printf("\n");
}

/* pause_before_exit: pause and wait for input before exiting */
void pause_before_exit(void)
{
	char buff[BUFFER_SIZE];

	printf("Press any key to exit...");
	get_line(buff, BUFFER_SIZE);
}



