/**
 * foo.c
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * Description: Functions from K&R.
 */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "foo.h"

/* (p69) get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = '\n';
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

/* (p61) str2int: convert s to integer */
int str2int(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')	/* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}

/* (p64) int2str: convert n to characters in s */
void int2str(int n, char s[])
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
	high = n - 1;
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
			for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
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

/* (p69) strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

/* (p71) str2double: convert string s to double */
double str2double(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) /* skip the white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}

/* (p87) quick_sort: sort v[left]...v[right] into increasing order */
void quick_sort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)  /* do nothing if array contains */
		return;     /* fewer than two elements */
	swap_v(v, left, (left + right)/2); /* move partition elem */
	last = left;                     /* to v[0] */
	for (i = left+1; i <= right; i++)
		if (v[i] < v[left])
			swap_v(v, ++last, i);
	swap_v(v, left, last);	/* restore partition elem */
	quick_sort(v, left, last-1);
	quick_sort(v, last+1, right);
}

/* (p88) swap_v: interchange v[i] and v[j] */
inline void swap_v(int v[], int i, int j)
{
	swap(v + i, v + j);
}

/* (p96) swap: interchange *px and *py */
void swap(int *px, int *py)
{
	int temp;

	temp = *px;
	*px = *py;
	*py = temp;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* (p111) day_of_year: set day of year from mont & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = leap_year(year);
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* (p111) month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = leap_year(year);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

/* (p113) month_name: return name of n-th month */
char *month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

/* (p156) minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap;	/* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);	/* clean up when done */
}

/* (p162) file_copy: copy file ifp to fill ofp */
void file_copy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

