#ifndef MOSYNC_ERRNO_H
#define MOSYNC_ERRNO_H

//#include <stdint.h>

extern int errno;

// Use this macro to define ERRNO in the main.c/cpp file
// of your app if it is not defined. You will get a linker
// error if it is not defined.
#ifndef LUA_DEFINE_ERRNO
#define LUA_DEFINE_ERRNO int errno = 0;
#endif

#endif
