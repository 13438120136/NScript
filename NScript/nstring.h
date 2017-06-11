#ifndef _NSTRING_HEAD
#define _NSTRING_HEAD

#include <stdlib.h>

typedef struct NMachine NMachine;

///�ַ�������
typedef struct NString
{
	int nsize;			 //��ǰ�ַ�������
	char buf[1];		 //ʵ���ַ������׵�ַ
}NString;

/***********************************************************************
  ����ȫ�ֵ��ַ������
  �������е��ַ�������
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
