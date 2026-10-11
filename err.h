#ifndef LIGHT_ERR_H
#define LIGHT_ERR_H
#include "core.h"

#define LIGHT_ERRMSG_MAX 50

#define LIGHT_OK           0
#define LIGHT_ERROR_MEMORY 1

extern LIGHT_THREAD_LOCAL int lerrno;
extern LIGHT_THREAD_LOCAL char lerrmsg[LIGHT_ERRMSG_MAX];

int light_raise(int err, const char *msg, ...);

#define LIGHT_CATCH(...) if (LIGHT_UNLIKELY(lerrno)) __VA_ARGS__

#endif
