#include "nlex.h"

void readToken(NLex *lex)
{
	NFile *file = lex->nFile;
	char ch = fileGetChar(file);

	switch(ch)
	{
	case ' ':
		break;
	default:
		break;
	}
}
