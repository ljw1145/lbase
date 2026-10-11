#ifndef LIGHT_CORE_H
#define LIGHT_CORE_H

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

#endif
