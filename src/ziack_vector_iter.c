/**
 * zimilo@code-trick.com
 */

#include "ziack_vector_iter.h"
#include "ziack_vector.h"
#include "ziack_memory.h"
#include "ziack_tests.h"

ziack_vector_iter_t *
ziack_vector_iter_create(ziack_vector_t *vec)
{
  ziack_vector_iter_t *it = (ziack_vector_iter_t *)ziack_calloc(1, sizeof(ziack_vector_iter_t));
  if (NULL == it) return NULL;
  it->vec = vec;
  it->idx = 0;
  return it;
}

ziack_bool_t
ziack_vector_iter_valid(ziack_vector_iter_t *it)
{
  return (it->idx >= ziack_vector_count(it->vec)) ? ZIACK_FALSE : ZIACK_TRUE;
}

void *
ziack_vector_iter_get_value(ziack_vector_iter_t *it)
{
  if (it->idx >= ziack_vector_count(it->vec)) return NULL;
  return ziack_vector_index(it->vec, it->idx);
}

ziack_rc_t
ziack_vector_iter_next(ziack_vector_iter_t *it)
{
  if (it->idx >= ziack_vector_count(it->vec)) return ZIACK_RC_ITER_GUARDER;
  ++it->idx;
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_vector_iter_destroy(ziack_vector_iter_t *it)
{
  ziack_free(it);
  return ZIACK_RC_OK;
}

#if 0
int
main(void)
{
  ziack_vector_t *v = ziack_vector_create(0);
  int a = 5, b = 6, c = 7, d = 8;
  ziack_vector_push(v, &a);
  ziack_vector_push(v, &b);
  ziack_vector_push(v, &c);
  ziack_vector_push(v, &d);
  
  ziack_vector_iter_t *it = ziack_vector_iter_create(v);
  void *value = NULL;
  while (ziack_vector_iter_valid(it)) {
    value = ziack_vector_iter_get_value(it);
    printf("%d\n", *(int *)value);
    ziack_vector_iter_next(it);
  }
  ziack_vector_iter_destroy(it);

  ziack_vector_destroy(v, NULL);
  return EXIT_SUCCESS;
}
#endif
