/**
 * memory_alloc.h
 *
 * Author: Mengqi Zong <zongmengqi@gmail.com>
 */

#ifndef __MEMORY_ALLOC_H
#define __MEMORY_ALLOC_H

#include <stdio.h>

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

void *memory_alloc(unsigned nbytes);
void memory_free(void *ap);


#endif /* __MEMORY_ALLOC_H */
