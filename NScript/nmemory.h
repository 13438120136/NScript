#ifndef _NMEMORY_HEAD
#define _NMEMORY_HEAD

#include <stdlib.h>
#include <memory.h>
#include <string.h>

///根据类型进行分配
#define mallocObject(type, count) (type *)memMalloc(NULL, sizeof(type) * count)
///重新空间大小
#define reallocObject(type, p, oldSize, newSize) 		\
	if (oldSize < newSize) 								\
	{													\
		oldSize = 2 * oldSize;							\
														\
		if (oldSize < 4)  								\
			oldSize = 4;								\
														\
		memMalloc(p, sizeof(type) * oldSize);			\
	}									 

///指定分配内存
extern void *memMalloc(void *src, int size);

#endif
