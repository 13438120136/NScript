#ifndef _NFILE_HEAD
#define _NFILE_HEAD

#include <stdio.h>

///文件预缓冲 用于缓冲读取文件字符
#define FILEBUFFER 256

typedef struct NFile
{
	FILE *m_fp;

	char buffer[FILEBUFFER];
	char *p;
	int ncount;
}NFile;

extern void fileInitalize(NFile *nfile);
///打开文件
extern void fileOpen(NFile *nfile, char *fileName);
///读取一个字符
extern char fileGetChar(NFile *nfile);
extern void fileDestory(NFile *nfile);
/*
 * 从文件中预先读取字符
 * nCount - 表示预先读取的字符个数
 */
extern char *filePreRead(NFile *nfile, int nCount);

#endif
