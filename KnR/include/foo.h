/*
 * foo.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 */

#ifndef __FOO_H
#define __FOO_H

#define BUFFER_SIZE 50
#define POWER_BASE 2
#define POWER_N 12
#define YEAR 2000


/* function declaration */
void exit_pause(void);
int power(int base, int n);
int get_line(char s[], int lim);
int leap_year(int year);
int str2num(char s[]);
int lower_case(int c);
int random(void);
void srandom(unsigned int seed);
unsigned get_bits(unsigned x, int p, int n);
int bit_count(unsigned x);


#endif /* __FOO_H */
