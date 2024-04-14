#include <errno.h>
// #include "pthread_impl.h"

int __errno_val;

int *__errno_location(void)
{
	// return &__pthread_self()->errno_val;
	return &__errno_val;
}

weak_alias(__errno_location, ___errno_location);
// int* (*___errno_location)(void) = __errno_location;
