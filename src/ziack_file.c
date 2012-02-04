#include "ziack_file.h"
#include "ziack_memory.h"
#include "ziack_tests.h"

ziack_file_t *
ziack_file_create(char *file_name)
{
  return NULL;
}

ziack_rc_t 
ziack_file_destroy(ziack_file_t *f)
{
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_file_write(ziack_file_t *f, 
		 void         *v, 
		 ziack_size_t  size)
{
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_file_read(ziack_file_t *f,
		void         *buf,
		uint64_t      offset,
		ziack_size_t  size)
{
  return ZIACK_RC_OK;
}
