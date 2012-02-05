/**
 * zimilo@code-trick.com
 */

#ifndef __ZIACK_FILE_H__
#define __ZIACK_FILE_H__

#include "ziack_config.h"
#include "ziack_types.h"

typedef struct __ZIACK_FILE {
  int     fd;
  off_t   size;
} ziack_file_t;

ziack_file_t *
ziack_file_create(char *file_name);

ziack_rc_t 
ziack_file_destroy(ziack_file_t *zf);

ziack_rc_t
ziack_file_write(ziack_file_t *zf, 
		 void         *v, 
		 ziack_size_t  size,
		 off_t        *roffset);

ziack_rc_t
ziack_file_read(ziack_file_t *zf,
		off_t         offset,
		ziack_size_t  size,
		void         *rbuf);

#endif // !__ZIACK_FILE_H__		
