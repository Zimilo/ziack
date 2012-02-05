/**
 * zimilo@code-trick.com
 */

#include "ziack_file.h"
#include "ziack_memory.h"
#include "ziack_tests.h"

ziack_file_t *
ziack_file_create(char *file_name)
{
  ziack_file_t *zf = (ziack_file_t *)ziack_calloc(1, sizoef(ziack_file_t));
  if (NULL == zf) return NULL;
  zf->fd = open(file_name, O_APPEND | O_RDWR | O_CREAT, 0666);
  if (-1 == zf->fd) {
    ziack_free(zf);
    return NULL;
  }
  zf->size = 0;
  return zf;
}

ziack_rc_t 
ziack_file_destroy(ziack_file_t *zf)
{
  close(zf->fd);
  ziack_free(zf);
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_file_write(ziack_file_t *zf, 
		 void         *v, 
		 ziack_size_t  size,
		 off_t        *roffset)
{
  off_t off = zf->size;
  ssize_t rc = write(zf->fd, v, size);
  if (-1 == rc) return ZIACK_RC_FILE_WRITE_ERROR;
  zf->size += rc;
  if (rc != size) return ZIACK_RC_FILE_WRITE_ERROR;
  *roffset = zf->size;
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_file_read(ziack_file_t *zf,
		off_t         offset,
		ziack_size_t  size,
		void         *rbuf)
{
  if (offset + size > zf->size) return ZIACK_RC_FILE_OVERFLOW_OFFSET;
  ssize_t rc = pread(zf->fd, rbuf, size, offset);
  if (-1 == rc || rc != size) return ZIACK_RC_FILE_READ_ERROR;
  return ZIACK_RC_OK;
}

