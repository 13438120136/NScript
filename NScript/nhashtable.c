#include "nhashtable.h"
#include "nstring.h"
#include <time.h>

#define HASHINITSIZE 256

void initNTable(NTable *t)
{
	t->value = newNodePointer(HASHINITSIZE);
	t->valueCount = HASHINITSIZE;
	memset(t->value, 0, sizeof(Node *) * HASHINITSIZE);

	t->valueIndex = 0;
	t->listCount = 0;
	t->valueList = NULL;
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
	reallocObject(TValue, t->valueList, t->listCount, index + 1);
	return &t->valueList[index];
}

TValue getObjFromKey(NTable *t, Tkey key)
{
	int index = getIndexFromNTable(t, key);
	TValue *result = getObjFromIndex(t, index);

	return *result;
}