#ifndef _NFILE_HEAD
#define _NFILE_HEAD

#include <stdio.h>

typedef struct NFile
{
	FILE *m_fp;
}NFile;

extern void fileInitalize(NFile *nfile);
extern char fileGetChar(NFile *nfile);
extern void fileDestory(NFile *nfile);

#endif
