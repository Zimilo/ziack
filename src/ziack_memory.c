/**
 * zimilo@code-trick.com
 */

#include "ziack_memory.h"
#include "ziack_tests.h"

#ifdef ZIACK_MEM_DEBUG
const uint32_t ziack_mem_magic_number = 0xA5E8C7F0;
#endif

void *
ziack_malloc(size_t size)
{
#ifdef ZIACK_MEM_DEBUG
  void *ptr = calloc(1, size + 8 + sizeof(size_t));
  if (NULL == ptr) return NULL;
  memcpy(ptr, &ziack_mem_magic_number, 4);
  memcpy(ptr + 4, &size, sizeof(size));
  memcpy(ptr + size + 8 + sizeof(size_t) - 4, &ziack_mem_magic_number, 4);
  return ptr + 4 + sizeof(size_t);
#else
  return malloc(size);
#endif
}

void *
ziack_calloc(size_t count,
	     size_t size)
{
#ifdef ZIACK_MEM_DEBUG
  return ziack_malloc(size * count);
#else
  return calloc(count, size);
#endif
}

void 
ziack_free(void *ptr)
{
#ifdef ZIACK_MEM_DEBUG
  void *p = ptr - 4 - sizeof(size_t);
  ziack_assert(*((uint32_t *)p) == ziack_mem_magic_number);
  size_t size = *((size_t *)(p + 4));
  ziack_assert(*((uint32_t *)(p + 4 + sizeof(size_t) + size)) == ziack_mem_magic_number);
  free(p);
  p = NULL;
#else
  free(ptr);
  ptr = NULL;
#endif
}

void *
ziack_realloc(void *ptr,
	      size_t size)
{
#ifdef ZIACK_MEM_DEBUG
  void *p = realloc(ptr - 4 - sizeof(size_t), 4 + sizeof(size_t) + size + 4);
  memcpy(p + 4, &size, sizeof(size));
  memcpy(p + 4 + sizeof(size_t) + size, &ziack_mem_magic_number, 4);
  return p + 4 + sizeof(size_t);
#else
  return realloc(ptr, size);
#endif
}

#ifdef ZIACK_MEM_DEBUG
size_t
ziack_malloc_size(void *ptr)
{
  return (*(size_t *)(ptr - sizeof(size_t)));
}
#endif
