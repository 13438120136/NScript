#ifndef _NCFUNCTION_HEAD
#define _NCFUNCTION_HEAD

#include "nmachine.h"

typedef int (*NFunction)(NMachine *machine);

///ԭʼC�����ṹ
typedef struct NCFunction
{
	NFunction func;		 //ʵ�ʵĺ���ָ��
	int sizeParam;		 //������������
	int sizeRet;		 //��������ֵ����
}NCFunction;

#endif
