#include "nmemory.h"

void *memMalloc(void *src, int size)
{
	void *mem = realloc(src, size);
	if (mem == NULL && size > 0)
	{
		if (src != NULL)
			free(src);
	}

	return mem;
}