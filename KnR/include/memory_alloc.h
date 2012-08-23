/**
 * memory_alloc.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef _MEMORY_ALLOC_H
#define _MEMORY_ALLOC_H

#define NALLOC 1024	/* minimum #units to request */

typedef long Align;	/* for alignment to long boundary */

union header {	/* block header */
	struct {
		union header *ptr;	/* next block if on free list */
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;

/* function declaration */
void *memory_alloc(unsigned nbytes);
void memory_free(void *ap);


#endif /* _MEMORY_ALLOC_H */
