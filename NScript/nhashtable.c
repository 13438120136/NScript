#include "nhashtable.h"
#include <time.h>
#include <stdlib.h>

#define HASHINITSIZE 256
#define HASHLISTSIZE 256

unsigned int hashString(const char *str, size_t size)
{
	//unsigned int seed = (unsigned int)time(NULL);
	unsigned int seed = 0;
	unsigned int h = seed ^ size;

	size_t l1;
	size_t step = (size >> 5) + 1;
	for (l1 = size; l1 >= step; l1 -= step)
		h = h ^ ((h<<5) + (h>>2) + (unsigned char)(str[l1 - 1]));

	return h;
}

void initNTable(NTable *t)
{
	t->value = newNodePointer(HASHINITSIZE);
	t->valueCount = HASHINITSIZE;
	memset(t->value, 0, sizeof(Node *) * HASHINITSIZE);

	t->valueIndex = 0;
	t->listCount = HASHLISTSIZE;
	t->valueList = newTValue(HASHLISTSIZE);
}

void addNTable(NTable *t, Tkey key, TValue value)
{
	int index = getIndexFromNTable(t, key);
	TValue *result = getObjFromIndex(t, index);
	setObjTo2(result, &value);
}

int getIndexFromNTable(NTable *t, Tkey key)
{
	unsigned int hashCode = hashString(key->buf, key->nsize);
	unsigned int hash = hashCode % t->valueCount;

	Node *first, **list;

	list = &t->value[hash];
	for (first = *list; first != NULL; first = first->nextNode)
	{
		if (memcmp(first->name->buf, key->buf, key->nsize) == 0)
				return first->index;
	}

	///没找到就分配新的节点
	first = newNode();
	first->index = t->valueIndex++;
	first->name = key;
	first->nextNode = *list;
	*list = first;

	return first->index;
}

TValue *getObjFromIndex(NTable *t, int index)
{
	return &t->valueList[index];
}

TValue getObjFromKey(NTable *t, Tkey key)
{
	int index = getIndexFromNTable(t, key);
	TValue *result = getObjFromIndex(t, index);

	return *result;
}