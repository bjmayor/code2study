#include "apue.h"
#include <sys/acct.h>

#ifdef HAS_SA_STAT
#define FMT "%-*.*s e = %6ld, chars = %7ld, stat = %3u: %c %c %c %c \n"
#else
#define FMT "%-*.*s e = %6ld, chars = %7ld,  %c %c %c %c \n"
#endif

#ifndef HAS_CORE
