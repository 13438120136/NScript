#include "nhashtable.h"
#include <time.h>
#include <stdlib.h>

#define LUAI_HASHLIMIT 5

unsigned int hashString(const char *str, size_t size)
{
	unsigned int seed = (unsigned int)time(NULL);
	unsigned int h = seed ^ size;

	size_t l1;
	size_t step = (size >> LUAI_HASHLIMIT) + 1;
	for (l1 = size; l1 >= step; l1 -= step)
		h = h ^ ((h<<5) + (h>>2) + (unsigned char)(str[l1 - 1]));

	return h;
}

void initNTable(NTable *t)
{	
	t->valueIndex = 0;
	t->valueCount = 177;
	t->listCount = 1024;
	t->valueList = (TValue *)malloc(t->listCount * sizeof(TValue));
}

void addNTable(NTable *t, Tkey key, TValue value)
{
	int hash = getIndexFromNTable(t, key);

	if (hash == -1)
	{
		TValue *obj = getObjFromIndex(t, t->valueIndex);
		t->value[hash]->index = t->valueIndex;
		t->valueIndex++;
		setObjTo2(*obj, value);
	}
	else
	{		
		int index = t->value[hash]->index;
		TValue *obj =getObjFromIndex(t, index);
		setObjTo2(*obj, value);
	}
}

int getIndexFromNTable(NTable *t, Tkey key)
{
	unsigned int hashCode = hashString(key, sizeof(key));
	unsigned int hash = hashCode % t->valueCount;

	if (t->value[hash] == NULL)
		return -1;

	return t->value[hash]->index;
}

TValue *getObjFromIndex(NTable *t, int index)
{
	TValue obj = t->valueList[index];
	return &obj;
}
