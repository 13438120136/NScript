#ifndef _NMEMORY_HEAD
#define _NMEMORY_HEAD

#include <stdlib.h>
#include <memory.h>
#include <string.h>

///�������ͽ��з���
#define mallocObject(type, count) (type *)memMalloc(NULL, sizeof(type) * count)
///���¿ռ��С
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

///ָ�������ڴ�
extern void *memMalloc(void *src, int size);

#endif
