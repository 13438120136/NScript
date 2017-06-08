#include "nfile.h"

void fileOpen(NFile *nfile, char *fileName)
{
	nfile->m_fp = fopen(fileName, "r");
}

void fileInitalize(NFile *nfile)
{
	nfile->ncount = 0;
	nfile->m_fp = NULL;
}

char fileGetChar(NFile *nfile)
{
	char ch;

	if (nfile->ncount > 0)
	{
		nfile->ncount--;
		ch =  *(nfile->p)++;
	}
	else
	{
		nfile->p = nfile->buffer;
		ch = fgetc(nfile->m_fp);
	}

	return ch;
}

void fileDestory(NFile *nfile)
{
	nfile->ncount = 0;

	if (nfile->m_fp != NULL)
	{
		fclose(nfile->m_fp);
		nfile->m_fp = NULL;
	}
}

char *filePreRead(NFile *nfile, int nCount)
{
	int n = fread(nfile->buffer, sizeof(char), nCount, nfile->m_fp);
	if (n == 0)
		return NULL;

	if (n > 0)
	{
		nfile->p = nfile->buffer;
		nfile->ncount = n;
	}

	return nfile->p;
}