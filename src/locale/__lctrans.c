#include <locale.h>
#include "locale_impl.h"

static const char *dummy__lctrans_impl(const char *msg, const struct __locale_map *lm)
{
	return msg;
}

weak_alias(dummy__lctrans_impl, __lctrans_impl);

const char *__lctrans(const char *msg, const struct __locale_map *lm)
{
	return __lctrans_impl(msg, lm);
}

const char *__lctrans_cur(const char *msg)
{
	return __lctrans_impl(msg, CURRENT_LOCALE->cat[LC_MESSAGES]);
}
