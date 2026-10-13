#ifndef LIGHT_LBASE_H
#define LIGHT_LBASE_H

#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
# define LIGHT_THREAD_LOCAL __declspec(thread)
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
# define LIGHT_THREAD_LOCAL _Thread_local
#elif defined(__GNUC__) || defined(__clang__)
# define LIGHT_THREAD_LOCAL __thread
#else
# define LIGHT_THREAD_LOCAL
# pragma message "Your compiler doesn't support thread local, so it's not safe to use multithreading."
#endif

#if defined(__GNUC__) || defined(__clang__)
# define LIGHT_INLINE      static inline __attribute__((always_inline))
# define LIGHT_FLATTEN     __attribute__((flatten))
# define LIGHT_LIKELY(x)   __builtin_expect(!!(x), 1)
# define LIGHT_UNLIKELY(x) __builtin_expect(!!(x), 0)
# define LIGHT_PURE        __attribute__((pure))
# define LIGHT_CONST       __attribute__((const))
# define LIGHT_NORETURN    __attribute__((noreturn))
#elif defined(_MSC_VER)
# define LIGHT_INLINE      static __forceinline
# define LIGHT_FLATTEN
# define LIGHT_LIKELY(x)   (x)
# define LIGHT_UNLIKELY(x) (x)
# define LIGHT_PURE
# define LIGHT_CONST
# define LIGHT_NORETURN
#else
# define LIGHT_INLINE      static inline
# define LIGHT_FLATTEN
# define LIGHT_LIKELY(x)   (x)
# define LIGHT_UNLIKELY(x) (x)
# define LIGHT_PURE
# define LIGHT_CONST
# define LIGHT_NORETURN
#endif

// exception

#define LIGHT_ERRMSG_MAX 100

#define LIGHT_OK                      0
#define LIGHT_ERROR_MEMORY            1
#define LIGHT_ERROR_VALUE             2
#define LIGHT_ERROR_DIVISION_BY_ZERO  3

extern LIGHT_THREAD_LOCAL int lerrno;
extern LIGHT_THREAD_LOCAL char lerrmsg[LIGHT_ERRMSG_MAX];

int light_raise(int err, const char *msg, ...);

#define light_memory_error(size)  light_raise(LIGHT_ERROR_MEMORY, "Unable to allocate memory (size=%zu).", size)
#define light_zero_division_error light_raise(LIGHT_ERROR_DIVISION_BY_ZERO, "Division by zero.")
#define light_zero_modulo_error   light_raise(LIGHT_ERROR_DIVISION_BY_ZERO, "Modulo by zero.")

#define LIGHT_CATCH(...)        if (LIGHT_UNLIKELY(lerrno)) __VA_ARGS__
#define LIGHT_FAIL              LIGHT_CATCH(return;)
#define LIGHT_FAIL_JUMP(jmp)    LIGHT_CATCH(goto jmp;)
#define LIGHT_FAIL_RETURN(ret)  LIGHT_CATCH(return ret;)

// types

typedef unsigned long long hash_t;

#ifdef __cplusplus
}
#endif

#endif
