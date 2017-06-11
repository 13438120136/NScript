#include "nstring.h"
#include "nmemory.h"
#include "nmachine.h"
#include <stdlib.h>

unsigned int hashString(const char *str, size_t size)
{
	unsigned int seed = 0;
	unsigned int h = seed ^ size;

	size_t l1;
	size_t step = (size >> 5) + 1;
	for (l1 = size; l1 >= step; l1 -= step)
		h = h ^ ((h<<5) + (h>>2) + (unsigned char)(str[l1 - 1]));

	return h;
}

void tableStrInit(NTableStr *table)
{
	table->list = mallocObject(NTableNode *, 1024);
}

///新建一个字符串对象
static NString *createNString(char *str, int size)
{
	NString *obj = (NString *)memMalloc(NULL, sizeof(NString) + size);
	obj->nsize = size;
	memcpy(obj->buf, str, size);
	obj->buf[size] = '\0';

	return obj;
}

NString *strNewString(NMachine *mac, char *str, int size)
{
	NString *obj = NULL;
	NTableStr *table = &(mac->strTable);

	unsigned int hashCode = hashString(str, size);
	unsigned int hash = hashCode % 1024;

	NTableNode *first, **list;

	list = &table->list[hash];
	for (first = *list; first != NULL; first = first->next)
	{
		if (first->strObj->nsize == size)
		{
			if (memcmp(first->strObj->buf, str, size) == 0)
				return first->strObj;
		}
	}

	obj = createNString(str, size);
	first = mallocObject(NTableNode, 1);
	first->strObj = obj;
	first->next = *list;
	*list = first;

	return obj;
}
