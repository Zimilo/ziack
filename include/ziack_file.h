/**
 * zimilo@code-trick.com
 */

#include "ziack_config.h"
#include "ziack_types.h"

ziack_file_t *
ziack_file_create(char *file_name);

ziack_rc_t 
ziack_file_destroy(ziack_file_t *f);

ziack_rc_t
ziack_file_write(ziack_file_t *f, 
		 void         *v, 
		 ziack_size_t  size);

ziack_rc_t
ziack_file_read(ziack_file_t *f,
		void         *buf,
		uint64_t      offset,
		ziack_size_t  size);


		
