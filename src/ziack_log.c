#include "ziack_log.h"
#include "ziack_memory.h"
#include "ziack_tests.h"
#include <fcntl.h>
#include <time.h>

char *ziack_log_level_strings[] = {"DEBUG", "WARN", "FATAL"};

ziack_log_t *
ziack_log_open(char *file_name, ziack_log_flag_t flags)
{
  int fd = open(file_name, O_APPEND | O_WRONLY | O_CREAT, 0666);
  if (-1 == fd) return NULL;
  ziack_log_t *log = (ziack_log_t *)ziack_calloc(1, sizeof(ziack_log_t) + strlen(file_name) + 1); // let filename be zero terminated
  if (NULL == log) {
    close(fd);
    return NULL;
  }
  log->flags = flags;
  log->fd = fd;
  log->buffer = (char *)ziack_calloc(1, ZIACK_LOG_BUFFER_DFT_SIZE);
  if (NULL == log->buffer) {
    close(fd);
    ziack_free(log);
    return NULL;
  }
  log->buffer_size = ZIACK_LOG_BUFFER_DFT_SIZE;
  log->size = lseek(fd, 0, SEEK_END);
  memcpy(log->filename, file_name, strlen(file_name));
  return log;
}

char *
ziack_log_level(ziack_log_level_t level)
{
  return ziack_log_level_strings[level - ZIACK_LOG_LEVEL_DEBUG];
}

ziack_rc_t
ziack_log_write(ziack_log_t       *log, 
		ziack_log_level_t  level,
		char              *msg,
		ziack_size_t       size)
{
  if (size > log->buffer_size) {
    log->buffer = (char *)ziack_realloc(log->buffer, size);
    log->buffer_size = size;
  }
  time_t now = time(NULL);
  struct tm now_tm;
  localtime_r(&now, &now_tm);
  snprintf(log->buffer, 
	   log->buffer_size,
	   "[%d-%02d-%02d %02d:%02d:%02d] [%d] [%s] %s\n", 
	   now_tm.tm_year + 1900,
	   now_tm.tm_mon + 1,
	   now_tm.tm_mday,
	   now_tm.tm_hour,
	   now_tm.tm_min,
	   now_tm.tm_sec,
	   (int)getpid(), 
	   ziack_log_level(level),
	   msg);
  log->size += write(log->fd, log->buffer, strlen(log->buffer));
  if (log->size >= ZIACK_LOG_FILE_SPLIT_SIZE) {
    close(log->fd);
    char filename[MAX_PATH] = {0};
    snprintf(filename, 
	     sizeof(filename), 
	     "%s.%d%02d%02d%02d%02d%02d",
	     log->filename,
	     now_tm.tm_year + 1900,
	     now_tm.tm_mon + 1,
	     now_tm.tm_mday,
	     now_tm.tm_hour,
	     now_tm.tm_min,
	     now_tm.tm_sec);
    rename(log->filename, filename);
    log->fd = open(log->filename, O_APPEND | O_WRONLY | O_CREAT, 0666);
  }
  return ZIACK_RC_OK;
}

ziack_rc_t
ziack_log_close(ziack_log_t *log)
{
  close(log->fd);
  ziack_free(log->buffer);
  ziack_free(log);
}

#if 0
int 
main(void)
{
  ziack_log_t *log = ziack_log_open("logs", ZIACK_LOG_FLAG_SPLIT_BY_SIZE);
  if (log == NULL) {
    printf("Cannot open log\n");
    return EXIT_FAILURE;
  }
  char *msg = "HelloMsg";
  ziack_log_write(log, ZIACK_LOG_LEVEL_DEBUG, msg, strlen(msg));
  ziack_log_close(log);
  return EXIT_SUCCESS;
}
#endif
