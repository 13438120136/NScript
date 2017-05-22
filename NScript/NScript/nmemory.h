#ifndef _NMEMORY_HEAD
#define _NMEMORY_HEAD

#include <stdlib.h>
#include <memory.h>
#include <string.h>

///根据类型进行分配
#define mallocObject(type, count) (type *)memMalloc(NULL, sizeof(type) * count)
///指定分配内存
extern void *memMalloc(void *src, int size);

#endif
