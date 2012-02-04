/**
 * zimilo@code-trick.com
 */

#ifndef __ZIACK_LOG_H__
#define __ZIACK_LOG_H__

#include "ziack_config.h"
#include "ziack_types.h"

typedef enum __ZIACK_LOG_FLAG {
  ZIACK_LOG_FLAG_SPLIT_BY_SIZE = 0x01,
} ziack_log_flag_t;

typedef enum __ZIACK_LOG_LEVEL {
  ZIACK_LOG_LEVEL_DEBUG   = 0,
  ZIACK_LOG_LEVEL_WARNING = 1,
  ZIACK_LOG_LEVEL_FATAL   = 2,
} ziack_log_level_t;

typedef struct __ZIACK_LOG {
  ziack_log_flag_t flags;
  int              fd;
  off_t            size;
  char            *buffer;
  ziack_size_t     buffer_size;
  char             filename[0];
} ziack_log_t;

#define ZIACK_LOG_BUFFER_DFT_SIZE 1024
#define ZIACK_LOG_FILE_SPLIT_SIZE (1 << 30)

ziack_log_t *
ziack_log_open(char *file_name, ziack_log_flag_t flags);

ziack_rc_t
ziack_log_write(ziack_log_t       *log, 
		ziack_log_level_t  level,
		char              *msg,
		ziack_size_t       size);

ziack_rc_t
ziack_log_close(ziack_log_t *log);

#endif // !__ZIACK_LOG_H__
