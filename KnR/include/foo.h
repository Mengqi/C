#ifndef __FOO_H
#define __FOO_H

/*
 * foo.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 * The primary test function for K&R.
 *
 */

#include <stdio.h>
#include <math.h>

#define POWER_BASE 2
#define POWER_N 12
#define YEAR 2000

void file_copy();
int power(int base, int n);
int get_line(char s[], int lim);
void copy(char to[], char from[]);
int leap_year(int year);
int str2num(char s[]);
int lower_case(int c);
int random(void);
int srandom(unsigned int seed);
unsigned get_bits(unsigned x, int p, int n);



#endif /* __FOO_H */
