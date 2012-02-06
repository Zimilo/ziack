/**
 * ziack@code-trick.com
 */

#ifndef __ZIACK_VECTOR_ITER_H__
#define __ZIACK_VECTOR_ITER_H__

#include "ziack_config.h"
#include "ziack_types.h"

ziack_vector_iter_t *
ziack_vector_iter_create(ziack_vector_t *vec);

ziack_bool_t
ziack_vector_iter_valid(ziack_vector_iter_t *it);

void *
ziack_vector_iter_get_value(ziack_vector_iter_t *it);

ziack_rc_t
ziack_vector_iter_next(ziack_vector_iter_t *it);

ziack_rc_t
ziack_vector_iter_destroy(ziack_vector_iter_t *it);

#endif // !__ZIACK_VECTOR_ITER_H__
