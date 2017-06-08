#ifndef _NHASHTABLE_HEAD
#define _NHASHTABLE_HEAD

#include "nobject.h"
#include "nmemory.h"
#include "nstring.h"

typedef NString *Tkey;
typedef NObject TValue;

typedef struct Node
{
	Tkey name;
	int index;
	struct Node *nextNode;
}Node;

typedef struct NTable
{
	Node **value;			   //ֵ
	unsigned int valueCount;   //ֵ����
							  
	TValue *valueList;		   //ֵ�б�
	int listCount;             //����
	int valueIndex;			   //����λ��
}NTable;

#define newNode() mallocObject(Node, 1)
#define newNodePointer(size) mallocObject(Node *, size)
#define newTValue(size) mallocObject(TValue, size)

///��ʼ�����
extern void initNTable(NTable *t);
///�ڱ�������key value
extern void addNTable(NTable *t, Tkey key, TValue value);
///�ڱ���л�ȡ��ֵ������ֵ
extern int getIndexFromNTable(NTable *t, Tkey key);
///���б��и�������ֵ��ȡʵ��value����
extern TValue *getObjFromIndex(NTable *t, int index);
///���ݼ�ֵ��ȡֵ
extern TValue getObjFromKey(NTable *t, Tkey key);

#endif
