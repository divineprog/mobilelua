#include <errno.h>

// This is to avoid duplicate definitions.
// Define this symbol if you are including
// another lib that defines errno (yajldom
// does for example).
#ifndef ERRNO_DEFINED
//int errno = 0;
#endif
