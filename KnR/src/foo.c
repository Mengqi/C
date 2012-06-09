#include <foo.h>

/* copy input to output */
void file_copy()
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; n--)
		p = p * base;
	return p;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] == '\n';
		i++;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	while ((to[i] = from[i]) != '\0')
		i++;
}

/* leap_year: return 1 if year is leap year; return 0 otherwise */
int leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

/* str2num: cnvert s to integer */
int str2num(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
		n = 10 * n + (s[i] - '0');
	}
	return n;
}

/* lower_case: convert c to lower case; ASCII only */
int lower_case(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

unsigned long int next = 1;

/* random: return pseudo-random integer on 0..32767 */
int random(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32767;
}

/* srandom: set seed for random() */
int srandom(unsigned int seed)
{
	next = seed;
}

/* get_bits: get n bits from position p */
unsigned get_bits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

/* bit_count: count 1 bits in x */
int bit_count(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1) {
		if (x & 01)
			b++;
	}

	return b;
}

