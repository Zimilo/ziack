/**
 * zimilo@code-trick.com
 */

#ifndef __ZIACK_MEMORY_H__
#define __ZIACK_MEMORY_H__

#include "ziack_config.h"
#include "ziack_types.h"

void *
ziack_malloc(size_t size);

void *
ziack_calloc(size_t count,
	     size_t size);

void 
ziack_free(void *ptr);

void *
ziack_realloc(void *ptr,
	      size_t size);

#ifdef ZIACK_MEM_DEBUG
size_t
ziack_malloc_size(void *ptr);
#endif

#endif // __ZIACK_MEMORY_H__
