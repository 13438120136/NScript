#ifndef _NMEMORY_HEAD
#define _NMEMORY_HEAD

#include <stdlib.h>
#include <memory.h>
#include <string.h>

///�������ͽ��з���
#define mallocObject(type, count) (type *)memMalloc(NULL, sizeof(type) * count)
///ָ�������ڴ�
extern void *memMalloc(void *src, int size);

#endif
