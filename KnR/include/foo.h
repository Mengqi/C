/*
 * foo.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 *
 */

#ifndef __FOO_H
#define __FOO_H

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 50
#define POWER_BASE 2
#define POWER_N 12
#define YEAR 2000

/* function declaration */
void foo(void);
void exit_pause(void);
int power(int base, int n);
int get_line(char s[], int lim);
int leap_year(int year);
int str2num(char s[]);
void num2str(int n, char s[]);
int lower_case(int c);
int random(void);
void srandom(unsigned int seed);
unsigned get_bits(unsigned x, int p, int n);
int bit_count(unsigned x);
int bin_search(int x, int v[], int n);
void shell_sort(int v[], int n);
void reverse(char s[]);
int trim(char s[]);
int strindex(char s[], char t[]);
double str2double(char s[]);
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

#endif /* __FOO_H */
