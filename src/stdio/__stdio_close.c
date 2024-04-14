#include "stdio_impl.h"
#include "aio_impl.h"

static int dummy__aio_close(int fd)
{
	return fd;
}

weak_alias(dummy__aio_close, __aio_close);

int __stdio_close(FILE *f)
{
	return syscall(SYS_close, __aio_close(f->fd));
}
