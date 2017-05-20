#include "nfile.h"

void fileInitalize(NFile *nfile)
{
	nfile->m_fp = NULL;
}

char fileGetChar(NFile *nfile)
{
	char ch = fgetc(nfile->m_fp);

	return ch;
}

void fileDestory(NFile *nfile)
{
	if (nfile->m_fp != NULL)
	{
		fclose(nfile->m_fp);
		nfile->m_fp = NULL;
	}
}
