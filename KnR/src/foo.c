/*
 * foo.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * All functions here.
 *
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include <foo.h>

/* foo: put test code here */
void foo(void)
{
	char buff[BUFFER_SIZE];
	
	num2str(123456, buff);
	printf("str = %s", buff);
}

/* exit_pause: wait for input before exit */
void exit_pause(void)
{
	char buff[BUFFER_SIZE];

	printf("Press any key to exit...");
	get_line(buff, BUFFER_SIZE);
}

/* (p27) power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; n--)
		p = p * base;
	return p;
}

/* (p29) get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}

/* (p41) leap_year: return 1 if year is leap year; return 0 otherwise */
int leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

/* (p61) str2num: cnvert s to integer */
int str2num(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-')? -1 : 1;
	if (s[i] == '+' || s[i] == '-')	/* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

/* (p64) num2str: convert n to characters in s */
void num2str(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;			/* make n positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* (p43) lower_case: convert c to lower case; ASCII only */
int lower_case(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

unsigned long int next = 1;

/* (p46) random: return pseudo-random integer on 0..32767 */
int random(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32767;
}

/* (p46) srandom: set seed for random() */
void srandom(unsigned int seed)
{
	next = seed;
}

/* (p49) get_bits: get n bits from position p */
unsigned get_bits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

/* (p50) bit_count: count 1 bits in x */
int bit_count(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1) {
		if (x & 01)
			b++;
	}
	return b;
}

/* (p58) bin_search: find x in v[0] <= v[1] <= ... <= v[n-1] */
int bin_search(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1; /* no match */
}

/* (p62) shell_sort: sort v[0]..v[n-1] into increasing order */
void shell_sort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}

/* (p62) reverse: reverse string s in place */
void reverse(char s[])
{
	int c,  i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* (p65) trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n+1] = '\0';
	return n;
}

