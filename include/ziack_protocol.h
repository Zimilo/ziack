#ifndef __ZIACK_PROTOCOL_H__
#define __ZIACK_PROTOCOL_H__

#include "ziack_config.h"
#include "ziack_types.h"

/**
 *  Protocol Definition
 *  
 *  ziack_rc_t zset(char *key, ziack_size_t key_size, char *value, ziack_size_t value_size);
 *  ziack_rc_t zvset(ziack_size_t version, char *key, ziack_size_t key_size, char *value, ziack_size_t value_size);
 *  void *zget(char *key, ziack_size_t key_size, ziack_rc_t *rc, ziack_size_t *value_size);
 *  void *zvget(ziack_size_t version, char *key, ziack_size_t key_size, ziack_rc_t *rc, ziack_size_t *value_size);
 *  ziack_rc_t zdelete(char *key, ziack_size_t key_size);
 *  
 *
 *
 *
 */

#endif // !__ZIACK_PROTOCOL_H__
