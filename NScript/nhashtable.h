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
	Node **value;			   //值
	unsigned int valueCount;   //值个数
							  
	TValue *valueList;		   //值列表
	int listCount;             //个数
	int valueIndex;			   //索引位置
}NTable;

#define newNode() mallocObject(Node, 1)
#define newNodePointer(size) mallocObject(Node *, size)
#define newTValue(size) mallocObject(TValue, size)

///初始化表格
extern void initNTable(NTable *t);
///在表格中添加key value
extern void addNTable(NTable *t, Tkey key, TValue value);
///在表格中获取键值的索引值
extern int getIndexFromNTable(NTable *t, Tkey key);
///在列表中根据索引值获取实际value对象
extern TValue *getObjFromIndex(NTable *t, int index);
///根据键值获取值
extern TValue getObjFromKey(NTable *t, Tkey key);

#endif
