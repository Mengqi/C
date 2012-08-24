/*
 * project_tools.c
 *
 * Functions for general purposes.
 *
 */

#include <stdio.h>

/*
 * Read a line (lim is the maxium length for the line) into s,
 * return length
 */
int get_line(char *s, int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';

	return i;
}
