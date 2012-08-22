/**
 * nlist.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef __NLIST_H
#define __NLIST_H

#include <stdio.h>
#include <stdlib.h>

struct nlist {		/* table entry: */
	char *name;		/* defined name */
	char *defn;		/* replacement text */
	struct nlist *next;	/* next entry in chain */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];	/* pointer table */

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

#endif /* __NLIST_H */
