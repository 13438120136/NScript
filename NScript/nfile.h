#ifndef _NFILE_HEAD
#define _NFILE_HEAD

#include <stdio.h>

///�ļ�Ԥ���� ���ڻ����ȡ�ļ��ַ�
#define FILEBUFFER 256

typedef struct NFile
{
	FILE *m_fp;

	char buffer[FILEBUFFER];
	char *p;
	int ncount;
}NFile;

extern void fileInitalize(NFile *nfile);
///���ļ�
extern void fileOpen(NFile *nfile, char *fileName);
///��ȡһ���ַ�
extern char fileGetChar(NFile *nfile);
extern void fileDestory(NFile *nfile);
/*
 * ���ļ���Ԥ�ȶ�ȡ�ַ�
 * nCount - ��ʾԤ�ȶ�ȡ���ַ�����
 */
extern char *filePreRead(NFile *nfile, int nCount);

#endif
