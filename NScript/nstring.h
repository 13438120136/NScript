#ifndef _NSTRING_HEAD
#define _NSTRING_HEAD

#include <stdlib.h>

typedef struct NMachine NMachine;

///字符串类型
typedef struct NString
{
	int nsize;			 //当前字符串长度
	char buf[1];		 //实际字符串的首地址
}NString;

/***********************************************************************
  定义全局的字符串表格
  保存所有的字符串对象
************************************************************************/
typedef struct NTableNode
{
	NString *strObj;
	struct NTableNode *next;
}NTableNode;

typedef struct NTableStr
{
	NTableNode **list;
}NTableStr;

unsigned int hashString(const char *str, size_t size);
NString *strNewString(NMachine *mac, char *str, int size);
void tableStrInit(NTableStr *table);

#endif
