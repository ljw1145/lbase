#include "err.h"
#include <stdio.h>
#include <stdarg.h>

LIGHT_THREAD_LOCAL int lerrno = 0;
LIGHT_THREAD_LOCAL char lerrmsg[LIGHT_ERRMSG_MAX];

int light_raise(int err, const char *msg, ...) {
    lerrno = err;
    va_list ap;
    va_start(ap, msg);
    int n = vsnprintf(lerrmsg, LIGHT_ERRMSG_MAX, msg, ap);
    va_end(ap);
    return n;
}
