#ifndef _NCFUNCTION_HEAD
#define _NCFUNCTION_HEAD

#include "nmachine.h"

typedef int (*NFunction)(NMachine *machine);

///原始C函数结构
typedef struct NCFunction
{
	NFunction func;		 //实际的函数指针
	int sizeParam;		 //函数参数个数
	int sizeRet;		 //函数返回值个数
}NCFunction;

#endif
