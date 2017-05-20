#ifndef _NLEX_HEAD
#define _NLEX_HEAD

#include "nfile.h"

#define LEX_SIZE 64

enum nLexKey
{
	KeyNone, KeyIF, KeyFor, KeyWhile, KeyBreak, KeyContinue, KeyReturn, Key,

	KeyAdd, KeySub, KeyMul, KeyDiv, KeyMod
};

char *nlex_token[] = {"if", "for", "while"};

typedef struct NLex
{
	NFile *nFile;

	char lexBuffer[LEX_SIZE];
	int lexSize;
}NLex;

extern void readToken(NLex *lex);

#endif
