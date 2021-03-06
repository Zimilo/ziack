#ifndef __ZIACK_HINT_TYPES_H__
#define __ZIACK_HINT_TYPES_H__

#include "ziack_config.h"

typedef struct __ZIACK_RECORD_KEY {
  uint32_t key_size;
  char     key[0];
} ziack_record_key_t;

typedef struct __ZIACK_RECORD_DATA {
  uint32_t data_size;
  char     data[0];
} ziack_record_data_t;

typedef struct __ZIACK_RECORD {
  uint64_t            magic_number;        // for recovery 
  char                cookie[64];          // brute force lookups
  ziack_record_key_t  key;                 
  uint32_t            flags;               // extra flag like delete flag and etc
  ziack_record_data_t data;                
  uint64_t            ts;
  uint64_t            crc;
  uint64_t            footer_magic_number; // footer magic number for recovery
  char                padding[0];          // bytes aligned to 8 bytes
} ziack_record_t;

typedef struct __ZIACK_HASHTABLE_KEY {
  ziack_size_t  key_size;
  char          key[0];
} ziack_hashtable_key_t;

typedef struct __ZIACK_HASHTABLE_ENTRY {
  ziack_hashtable_key_t          *key;
  void                           *value;
  uint32_t                        hash;
  struct __ZIACK_HASHTABLE_ENTRY *next;
} ziack_hashtable_entry_t;

typedef struct __ZIACK_HASHTABLE {
  ziack_hashtable_entry_t **buckets;
  ziack_size_t bucket_count;
  ziack_size_t entry_count;
  uint32_t (*hashfunc)(void *key, ziack_size_t key_size);
  ziack_rc_t (*key_equal_func)(void *key, ziack_size_t key_size, void *value, ziack_size_t value_size);
} ziack_hashtable_t;

typedef struct __ZIACK_HASHTABLE_ITER {
  ziack_hashtable_t       *h;
  ziack_hashtable_entry_t *entry;
  ziack_hashtable_entry_t *entry_parent;
  ziack_size_t             idx;
} ziack_hashtable_iter_t;

typedef struct __ZIACK_VECTOR {
  ziack_size_t count;
  ziack_size_t capacity;
  void       **data;
} ziack_vector_t;

typedef struct __ZIACK_VECTOR_ITER {
  ziack_vector_t *vec;
  ziack_size_t    idx;
} ziack_vector_iter_t;

typedef struct __ZIACK_HINT_VERSION {
  ziack_flag_t flags; 
  uint64_t     ts;
  ziack_size_t fidx;
  uint64_t     offset; 
  ziack_size_t size;
} ziack_hint_version_t;

typedef struct __ZIACK_HINT_VALUE {
  ziack_size_t    base;
  ziack_vector_t *versions;
} ziack_hint_value_t;

typedef struct __ZIACK_HINT {
  ziack_hashtable_t *hints;
} ziack_hint_t;

typedef struct __ZIACK_HINT_KEY {
  ziack_size_t  key_size;
  char          key[0];
} ziack_hint_key_t;

typedef struct __ZIACK_RUNTIME {
  ziack_hint_t   *hint;
  //ziack_file_t   *active_file;
  ziack_vector_t *old_files;
  //ziack_log_t    *log;
} ziack_runtime_t;

#endif // __ZIACK_HINT_TYPES_H__
