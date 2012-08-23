/**
 * nlist.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _NLIST_H
#define _NLIST_H

struct nlist {		/* table entry: */
	char *name;		/* defined name */
	char *defn;		/* replacement text */
	struct nlist *next;	/* next entry in chain */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];	/* pointer table */

/* function declaration */
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

#endif /* _NLIST_H */
