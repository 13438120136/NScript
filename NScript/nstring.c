#include "nstring.h"
#include "nmemory.h"

NString *strNewString(char *str, int size)
{
	NString *obj = (NString *)memMalloc(NULL, sizeof(NString) + size);
	obj->nsize = size;
	memcpy(obj->buf, str, size);
	obj->buf[size] = '\0';

	return obj;
}
