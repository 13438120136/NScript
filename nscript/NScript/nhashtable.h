#ifndef _NHASHTABLE_HEAD
#define _NHASHTABLE_HEAD

#include "nobject.h"

typedef char * Tkey;
typedef NObject TValue;

typedef struct Node
{
	Tkey name;
	int index;
}Node;

typedef struct NTable
{
	Node **value;			   //ֵ
	unsigned int valueCount;   //ֵ����
							  
	TValue *valueList;		   //ֵ�б�
	int listCount;             //����
	int valueIndex;			   //����λ��
}NTable;

extern void initNTable(NTable *t);
extern void addNTable(NTable *t, Tkey key, TValue value);
extern int getIndexFromNTable(NTable *t, Tkey key);
extern TValue *getObjFromIndex(NTable *t, int index);

#endif
