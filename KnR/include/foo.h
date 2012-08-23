/**
 * foo.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _FOO_H
#define _FOO_H

#include <stdio.h>

/* function declaration */
int get_line(char s[], int lim);
int leap_year(int year);
int str2int(char s[]);
void int2str(int n, char s[]);
unsigned get_bits(unsigned x, int p, int n);
int bit_count(unsigned x);
int bin_search(int x, int v[], int n);
void shell_sort(int v[], int n);
void reverse(char s[]);
int trim(char s[]);
int strindex(char s[], char t[]);
double str2double(char s[]);
void quick_sort(int v[], int left, int right);
inline void swap_v(int v[], int i, int j);
void swap(int *px, int *py);
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);
void minprintf(char *fmt, ...);
void file_copy(FILE *ifp, FILE *ofp);


#endif /* _FOO_H */
