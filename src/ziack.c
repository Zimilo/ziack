/**
 * zimilo@code-trick.com
 */

#include "ziack.h"
#include "ziack_memory.h"
#include "ziack_hint.h"
#include "ziack_file.h"
#include "ziack_vector.h"
#include <signal.h>

ziack_t *z = NULL;

ziack_rc_t
ziack_server_start()
{
  z = (ziack_t *)ziack_calloc(1, sizeof(ziack_t));
  z->hint = ziack_hint_create(0);
  z->active_file = ziack_file_open();
  z->old_fileds = ziack_vector_create(0);
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_server_stop()
{
  return ZIACK_RC_OK;
}

int 
main(int argc, char **argv) 
{
  if (ziack_server_start() != ZIACK_RC_OK) {
    
  }
  
  return EXIT_SUCCESS;
}
